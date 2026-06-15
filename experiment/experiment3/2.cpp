#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void dfs(vector<string> &res, int n, int open, int close, string cur)
{
    if (cur.length() == n * 2)
    {
        res.push_back(cur);
        return;
    }

    if (open < n)
    {
        dfs(res, n, open + 1, close, cur + '(');
    }
    if (close < open)
    {
        dfs(res, n, open, close + 1, cur += ')');
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> res;
    dfs(res, n, 0, 0, "");

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}