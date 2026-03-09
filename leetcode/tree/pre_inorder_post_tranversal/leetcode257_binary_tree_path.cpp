#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;

    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val, TreeNode *_left, TreeNode *_right, TreeNode *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    void getpath(TreeNode*root,vector<string>&path,string&s)
    {
        if(!root)
        {
            path.push_back(s);
            return;
        }
        s.push_back(root->val);
        getpath(root->left, path, s);
        getpath(root->right, path, s);
        s.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string s = "";
        vector<string> path;
        getpath(root, path, s);
        return path;
    }
};