#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<queue>
#include <cassert>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr)
    {

    }

    TreeNode(int x):val(x),left(nullptr),right(nullptr)
    {

    }

    TreeNode(int x,TreeNode*left,TreeNode*right):val(x),left(left),right(right)
    {

    }
};

class Solution
{
public:
    void traversal(TreeNode*cur,vector<int>&v)
    {
        if(!cur)
        {
            return;
        }
        v.push_back(cur->val);
        traversal(cur->left, v);
        traversal(cur->right, v);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> v1={};
        traversal(root, v1);
        return v1;
    }

    vector<int>preorderTraversal1(TreeNode*root)
    {
        if(!root)
        {
            return {};
        }

        vector<int> res = {};
        res.push_back(root->val);

        vector<int> left_res = preorderTraversal1(root->left);
        vector<int> right_res = preorderTraversal1(root->right);
        res.insert(res.end(), left_res.begin(), left_res.end());
        res.insert(res.end(), right_res.begin(), right_res.end());

        return res;
    }
};

TreeNode* buildtree(vector<string> nodes)
{
    if(nodes.empty()||nodes[0]=="null")
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while(!q.empty()&&i<nodes.size())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (i < nodes.size()&&nodes[i]!="null")
        {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != "null")
        {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}


int main()
{
    vector<string> vs;
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    while (getline(ss,token,','))
    {
        vs.push_back(token);
    }

    TreeNode *root = buildtree(vs);
    Solution s1;
    vector<int> res1 = s1.preorderTraversal(root);
    vector<int> res2 = s1.preorderTraversal1(root);
    for(int a:res1)
    {
        cout << a << " ";
    }
    cout << endl;

    assert(res1.size() == res2.size() && "mismatch");
    assert(res1 == res2 && "not equivalent");
    cout << "all right" << endl;

    return 0;
}