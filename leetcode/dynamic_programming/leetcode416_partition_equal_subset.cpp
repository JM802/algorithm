#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        int target = sum / 2;

        vector<int> dp(10001, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool canPartition1(vector<int> &nums, int total, int sum, int startindex)
    {
        if (total % 2 != 0)
        {
            return false;
        }

        if (sum > total / 2)
        {
            return false;
        }

        if (sum == total / 2)
        {
            return true;
        }

        for (int i = startindex; i < nums.size(); i++)
        {
            sum += nums[i];
            bool flag = canPartition1(nums, total, sum, i + 1);
            if (flag)
            {
                return true;
            }
            sum -= nums[i];
        }
        return false;
    }
};
