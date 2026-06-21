#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        if (nums.size() == 0)
        {
            return 0;
        }
        int result = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            if (dp[i] > result)
            {
                result = dp[i];
            }
        }
        return result;
    }

    int findLengthOfLCIS1(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int count = 1;
        int result = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count > result)
            {
                result = count;
            }
        }
        return result;
    }
};