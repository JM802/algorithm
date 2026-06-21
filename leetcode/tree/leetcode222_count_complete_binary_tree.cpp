#include <iostream>
#include <vector>
#include <queue>
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
    int countNodes(TreeNode *root)
    {
        queue<TreeNode *> q;
        if(!root)
        {
            return 0;
        }
        q.push(root);
        int count = 0;

        while(!q.empty())
        {
            int size = q.size();
            count += size;
            for (int i = 0; i < size;i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left)
                {
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                }
            }
        }
        return count;
    }

    int countNodes1(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }

        int leftcount = countNodes1(root->left);
        int rightcount = countNodes1(root->right);
        int count = leftcount + rightcount + 1;
        return count;
    }
};