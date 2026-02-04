#include<iostream>
#include<vector>
using namespace std;


class TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    
    TreeNode():val(0),left(nullptr),right(nullptr)
    {

    }

    TreeNode(int x):val(x),left(nullptr),right(nullptr)
    {

    }
};

int main()
{
    vector<int> v1={1,4,3};
    for (int i = 0; i < v1.size();i++)
    {
        for (int j = 0; j < v1[i];j++)
        {
            cout << "hello world" << endl;
        }
    }
    return 0;
}