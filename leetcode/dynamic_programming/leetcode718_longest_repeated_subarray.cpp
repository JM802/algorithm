#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int findLength1(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result)
                    result = dp[i][j];
            }
        }
        return result;
    }

    int findLength1(vector<int> &nums1, vector<int> &nums2)
    {
        int result = 0;
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));

        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums2[j] == nums1[0])
            {
                dp[0][j] = 1;
            }
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == nums2[0])
            {
                dp[i][0] = 1;
            }
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j] && i > 0 && j > 0)
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result)
                {
                    result = dp[i][j];
                }
            }
        }
        return result;
    }
};