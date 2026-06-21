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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }

        if(!root->left&&!root->right)
        {
            return 0;
        }

        int mid = 0;

        if(root->left&&!root->left->left&&!root->left->right)
        {
            mid = root->left->val;
        }

        int leftsum = mid + sumOfLeftLeaves(root->left);
        int rightsum = sumOfLeftLeaves(root->right);
        int sum = leftsum + rightsum;
        return sum;
    }
};