#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getmaxvalue(int m,int n,vector<int>&spaces,vector<int>&values)
{
    vector<vector<int>>dp(m,vector<int>(n+1,0));
    for (int i = 0; i < m;i++)
    {
        dp[i][0] = 0;
    }
    for (int j = spaces[0]; j <=n; j++)
    {
        dp[0][j] = values[0];
    }
    for (int i = 1; i < m;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if(spaces[i]>j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - spaces[i]] + values[i]);
            }
        }
    }
    return dp[m - 1][n];
}

int getmaxvalue1(int m,int n,vector<int>&spaces,vector<int>&values)
{
    vector<int>dp(n+1,0);
    for (int i = 0; i < m;i++)
    {
        for (int j = n; j >= spaces[i];j--)
        {
            dp[j] = max(dp[j], dp[j - spaces[i]] + values[i]);
        }
    }
    return dp[n];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> spaces(m, 0);
    vector<int> values(m, 0);
    for (int i = 0; i < m;i++)
    {
        cin >> spaces[i];
    }
    for (int i = 0; i < m;i++)
    {
        cin >> values[i];
    }
    int res = getmaxvalue1(m, n, spaces, values);
    cout << res << endl;
    return 0;
}