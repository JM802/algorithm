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
    void backtracing(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracing(nums, used);
        return res;
    }
};