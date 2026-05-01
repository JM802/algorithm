#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getmaxvalue(int n,int v,vector<int>&weights,vector<int>&values)
{
    vector<int> dp(v + 1, 0);
    dp[0] = 0;

    for (int i = 0; i < n;i++)
    {
        for (int j = weights[i]; j <= v;j++)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[v];
}

int main()
{
    int n, v;
    cin >> n >> v;
    vector<int> weights(n, 0);
    vector<int> values(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
        cin >> values[i];
    }
    int res = getmaxvalue(n, v, weights, values);
    cout << res << endl;
    return 0;
}