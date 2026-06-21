#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool ispalindromicz(int start, int end, string s)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
    int countSubstrings(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        result++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1])
                    {
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }

    int countSubstrings1(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (ispalindromicz(i, j, s))
                {
                    count++;
                }
            }
        }
        return count;
    }
};