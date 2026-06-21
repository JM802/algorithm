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
    void tranversal(TreeNode*root,vector<string>&res,vector<int>&path)
    {
        if(!root)
        {
            return;
        }

        path.push_back(root->val);

        if(!root->left&&!root->right)
        {
            string s="";
            for (int i = 0; i < path.size(); i++)
            {
                if(i!=path.size()-1)
                {
                    s += to_string(path[i]);
                    s += "->";
                }
                else
                {
                    s += to_string(path[i]);
                }
            }
            res.push_back(s);
            return;
        }

        if(root->left)
        {
            tranversal(root->left, res, path);
            path.pop_back();
        }

        if (root->right)
        {
            tranversal(root->right, res, path);
            path.pop_back();
        }
        return;
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int>path;
        vector<string> res;
        tranversal(root, res, path);
        return res;
    }
};
