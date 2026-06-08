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
    void backtracing(vector<int> &nums, int startindex, vector<bool> &used)
    {
        if (path.size() >= 2)
        {
            res.push_back(path);
        }
        if (startindex >= nums.size())
        {
            return;
        }

        for (int i = startindex; i < nums.size(); i++)
        {
            if ((i < nums.size() - 1) || (nums[i] <= nums[i + 1]))
            {
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
    }
};