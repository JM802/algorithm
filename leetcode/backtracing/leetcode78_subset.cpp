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
    void backtracing(const vector<int> &nums, int startindex)
    {
        res.push_back(path);
        if (startindex >= nums.size())
        {
            return;
        }
        for (int i = startindex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracing(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        res.clear();
        path.clear();
        backtracing(nums, 0);
        return res;
    }
};