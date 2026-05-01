#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> res;
vector<int> path;

class Solution
{
public:
    void backtracing(int n,int k,int startindex)
    {
        if(path.size()==k)
        {
            res.push_back(path);
            return;
        }
        for (int i = startindex; i <= n-(k-path.size())+1;i++)
        {
            path.push_back(i);
            backtracing(n, k, i + 1);
            path.pop_back();
        }
    }


    vector<vector<int>> combine(int n, int k)
    {
        backtracing(n, k, 1);
        return res;
    }
};