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
    int res = 0;
    int depth = 0;

    void tranversal(TreeNode*root,int&d)
    {
        if(!root)
        {
            return;
        }
        if(!root->left&&!root->right)
        {
            if(d>depth)
            {
                depth = d;
                res = root->val;
            }
            return;
        }
        if(root->left)
        {
            d ++;
            tranversal(root->left, d);
            d--;
        }
        if(root->right)
        {
            d++;
            tranversal(root->right, d);
            d--;
        }
    }

    int findBottomLeftValue(TreeNode *root)
    {
        int d = 1;
        tranversal(root, d);
        return res;
    }
};