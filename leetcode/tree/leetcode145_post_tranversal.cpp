#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v):val(v),left(nullptr),right(nullptr)
    {

    }
};

class Solution
{
public:
    void tranversal(TreeNode*cur,vector<int>&v)
    {
        if(!cur)
        {
            return;
        }
       
        tranversal(cur->left, v);
        tranversal(cur->right, v);
        v.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res = {};
        tranversal(root, res);
        return res;
    }
};

TreeNode* buildtree(vector<string>nodes)
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
        if(i<nodes.size()&&nodes[i]!="null")
        {
            TreeNode *left = new TreeNode(stoi(nodes[i]));
            cur->left = left;
            q.push(left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null")
        {
            TreeNode *right = new TreeNode(stoi(nodes[i]));
            cur->right = right;
            q.push(right);
        }
        i++;
    }
    return root;
}

int main()
{
    vector<string> nodes;
    string line;
    getline(cin, line);

    for(char&c:line)
    {
        if(c==',')
        {
            c = ' ';
        }
    }

    stringstream ss(line);
    string token;
    while(ss>>token)
    {
        nodes.push_back(token);
    }
    TreeNode *root = buildtree(nodes);
    Solution s;
    vector<int> res = s.postorderTraversal(root);
    for(int a:res)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}