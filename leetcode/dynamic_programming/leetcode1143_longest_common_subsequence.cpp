#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }

    int longestCommonSubsequence1(string text1, string text2)
    {
        int result = 0;
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));

        for (int j = 0; j < text2.size(); j++)
        {
            if (text1[0] == text2[j])
            {
                dp[0][j] = 1;
            }
        }

        for (int i = 0; i < text1.size(); i++)
        {
            if (text2[0] == text1[i])
            {
                dp[i][0] = 1;
            }
        }

        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1;
                    for (int k = 0; k < i; k++)
                    {
                        for (int m = 0; m < j; m++)
                        {
                            if (text1[k] == text2[m])
                                dp[i][j] = max(dp[i][j], dp[k][m] + 1);
                        }
                    }
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