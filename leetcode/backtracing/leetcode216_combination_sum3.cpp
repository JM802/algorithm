#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> res;
vector<int> path;

class Solution
{
public:
    void backtracing(int k,int n,int sum,int startindex)
    {
        if (sum > n)
        {
            return;
        }
        if(path.size()==k)
        {
            if(sum==n)
            {
                res.push_back(path);
            }
            return;
        }
        for (int i = startindex; i <= 9 - (k - path.size()) + 1;i++)
        {
            sum += i;
            path.push_back(i);
            backtracing(k, n, sum, i + 1);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        res.clear();
        path.clear();
        backtracing(k, n, 0, 1);
        return res;
    }
};