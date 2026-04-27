#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        for(string str:strs)
        {
            int x=0;
            int y=0;
            for (int i = 0; i < str.size();i++)
            {
                if(str[i]=='0')
                {
                    x++;
                }
                else
                {
                    y++;
                }
            }

            for (int i = m; i >= x;i--)
            {
                for (int j = n; j >= y;j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - x][j - y] + 1);
                }
            }
        }
        return dp[m][n];
    }
};