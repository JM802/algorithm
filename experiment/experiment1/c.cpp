#include <iostream>
#include <vector>
using namespace std;

int getlongest(int n,vector<int>&p1,vector<int>&p2)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if(p1[i]==p2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> p1(n + 1);
    vector<int> p2(n + 1);
    for (int i = 1; i <= n;i++)
    {
        cin >> p1[i];
    }
    for (int j = 1; j <= n;j++)
    {
        cin >> p2[j];
    }
    int res = getlongest(n, p1, p2);
    cout << res << endl;
    return 0;
}