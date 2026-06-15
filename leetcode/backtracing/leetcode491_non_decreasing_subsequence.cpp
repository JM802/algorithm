#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

vector<vector<int>> res;
vector<int> path;

class Solution
{
public:
    void backtracing(vector<int> &nums, int startindex)
    {
        if (path.size() >= 2)
        {
            res.push_back(path);
        }

        if (startindex >= nums.size())
        {
            return;
        }

        unordered_set<int> uset;
        for (int i = startindex; i < nums.size(); i++)
        {
            if ((uset.find(nums[i]) != uset.end()) || (path.size() >= 1 && nums[i] < path.back()))
            {
                continue;
            }

            else
            {
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                backtracing(nums, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        res.clear();
        path.clear();
        backtracing(nums, 0);
        return res;
    }
};