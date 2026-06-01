#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

vector<vector<int>> res;
vector<int> path;

class Solution
{
public:
    void getcombinationsum(vector<int>&candidates,int target,int sum,int startindex)
    {
        if(sum==target)
        {
            res.push_back(path);
            return;
        }
        for (int i = startindex; i < candidates.size()&&sum+candidates[i]<=target;i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            getcombinationsum(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        getcombinationsum(candidates, target, 0, 0);
        return res;
    }
};