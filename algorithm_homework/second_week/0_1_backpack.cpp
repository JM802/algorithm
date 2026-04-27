#include <iostream>
#include <vector>
using namespace std;

int getmaxvalue(int n, int w, vector<int> &values, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = weight[0]; j <= w; j++)
    {
        dp[0][j] = values[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j > weight[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + values[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n - 1][w + 1];
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    int res = getmaxvalue(n, w, values, weights);
    cout << res << endl;
    return 0;
}