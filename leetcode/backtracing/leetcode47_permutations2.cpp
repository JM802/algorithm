#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracing(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false)
            {
                continue;
            }
            else if (used[i] == true)
            {
                continue;
            }

            else
            {
                used[i] = true;
                path.push_back(nums[i]);
                backtracing(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracing(nums, used);
        return res;
    }
};