#include <iostream>
#include <vector>
#include <string>
#include<cmath>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;

        for (int i = 0; i < nums.size();i++)
        {
            sum += nums[i];
        }

        int real = (target+sum)/2;
        if ((target + sum) % 2 != 0)
        {
            return 0;
        }

        if(abs(target)>sum)
        {
            return 0;
        }

        vector<vector<int>>dp(nums.size(),vector<int>(real+1,0));
        if(nums[0]<=real)
        {
            dp[0][nums[0]] = 1;
        }

        dp[0][0] = 1;

        int countzero = 0;
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i]==0)
            {
                countzero++;
            }
            dp[i][0] = (int)pow(2.0, countzero);
        }

        for (int i = 1; i < nums.size();i++)
        {
            for (int j = 1; j <= real;j++)
            {
                if(nums[i]>j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][real];
    }

    int findTargetSumWays1(vector<int> &nums, int target)
    {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        int real = (target + sum) / 2;
        if ((target + sum) % 2 != 0)
        {
            return 0;
        }

        if (abs(target) > sum)
        {
            return 0;
        }
        vector<int> dp(real + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size();i++)
        {
            for (int j = real; j >= nums[i];j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[real];
    }
};