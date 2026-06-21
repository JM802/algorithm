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
    int maxDepth(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }

        int leftmax = maxDepth(root->left);
        int rightmax = maxDepth(root->right);

        return max(leftmax, rightmax) + 1;
    }
};