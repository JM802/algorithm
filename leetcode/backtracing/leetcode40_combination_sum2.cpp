#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<set>
using namespace std;

vector<vector<int>> res;
vector<int> path;

class Solution
{
public:
    void backtracing(const int&target,int sum,vector<int>&candiates,int startindex,vector<bool>&used)
    {
        if(sum==target)
        {
            res.push_back(path);
            return;
        }

        for (int i = startindex; i < candiates.size()&&sum+candiates[i]<=target;i++)
        {
            if(i>0&&candiates[i-1]==candiates[i]&&used[i-1]==false)
            {
                continue;
            }
            sum += candiates[i];
            path.push_back(candiates[i]);
            used[i] = true;
            backtracing(target, sum, candiates, i + 1,used);
            used[i] = false;
            sum -= candiates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        res.clear();
        path.clear();
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracing(target, 0, candidates, 0,used);
        return res;
    }
};