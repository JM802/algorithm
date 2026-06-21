#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        if(!root->left&&!root->right)
        {
            return 1;
        }

        int leftmin = minDepth(root->left);
        int rightmin = minDepth(root->right);

        if(!root->left)
        {
            return rightmin + 1;
        }
        if(!root->right)
        {
            return leftmin + 1;
        }

        return min(leftmin, rightmin) + 1;
    }
};