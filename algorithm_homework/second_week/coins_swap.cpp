#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getmincount(int n, int y, vector<int> coins)
{
    vector<int> dp(y + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= y; j++)
        {
            if (dp[j - coins[i]] != INT_MAX)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }
    return dp[y] == INT_MAX ? -1 : dp[y];
}