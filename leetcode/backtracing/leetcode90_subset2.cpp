#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> res;
vector<int> path;

class Solution
{
public:
    void backtracing(vector<int>&nums,int startindex,vector<bool>&used)
    {
        res.push_back(path);
        if(startindex>=nums.size())
        {
            return;
        }

        for (int i = startindex;i<nums.size();i++)
        {
            if((i>0)&&(nums[i-1]==nums[i])&&(used[i-1]==false))
            {
                continue;
            }
            else
            {
                path.push_back(nums[i]);
                used[i] = true;
                backtracing(nums, i + 1, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracing(nums, 0, used);
        return res;
    }
};