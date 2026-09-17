#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        for (int i = 0; i < k; i++)
        {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res += nums[i];
        }
        return res;
    }
};