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
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int result = dp[0];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }

    int maxSubArray1(vector<int> &nums)
    {
        int result = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count < 0)
            {
                count = nums[i];
            }
            else
            {
                count += nums[i];
            }
            result = max(result, count);
        }
        return result;
    }
};