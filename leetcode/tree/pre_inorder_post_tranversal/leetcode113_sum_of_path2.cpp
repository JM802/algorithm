#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
    void tranversal(TreeNode*root,int targetSum,int sum,vector<int>&path,vector<vector<int>>&res)
    {
        if(!root->left&&!root->right)
        {
            if(targetSum==sum)
            {
                res.push_back(path);
            }
            return;
        }

        if(root->left)
        {
            path.push_back(root->left->val);
            tranversal(root->left, targetSum, sum + root->left->val, path, res);
            path.pop_back();
        }

        if(root->right)
        {
            path.push_back(root->right->val);
            tranversal(root->right, targetSum, sum + root->right->val, path, res);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if(!root)
        {
            return {{}};
        }
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(root->val);
        int sum = root->val;
        tranversal(root, targetSum, sum, path, res);
        return res;
    }
};