#include <iostream>
#include <vector>
#include <string>

using namespace std;

int climbstairs(int n,int m)
{
    vector<int> dp(n + 1,0);
    dp[0]=1;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if(i>=j)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int res = climbstairs(n, m);
    cout << res << endl;
    return 0;
}