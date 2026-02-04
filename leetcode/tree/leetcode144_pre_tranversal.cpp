#include<iostream>
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

vector<int> v1;

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(root==nullptr)
        {
            return v1;
        }
        v1.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return v1;
    }
};


int main()
{

}