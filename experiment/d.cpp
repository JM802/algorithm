#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

int min_mod = INT_MAX;
string res;
int n, p;

void update(string s, int sum)
{
    int mod = sum % p;
    if (mod < min_mod)
    {
        res = s;
        min_mod = mod;
    }
    else if (mod == min_mod)
    {
        if (s < res)
        {
            res = s;
        }
    }
}

void dfs(int pos, string s, int sum)
{
    if (pos == n)
    {
        update(s, sum);
        return;
    }

    int startindex = (pos == 0) ? 1 : 0;

    for (int i = startindex; i <= 9; i++)
    {
        dfs(pos + 1, s + char('0' + i), sum + i);
    }
}

int main()
{
    cin >> n >> p;
    dfs(0, "", 0);
    cout << res << endl;
    return 0;
}