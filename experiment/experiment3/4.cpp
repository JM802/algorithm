#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool used[26] = {false};
bool haschar(string s)
{
    bool temp[26] = {false};
    for (char c : s)
    {
        int idx = c - 'a';
        if (used[idx] || temp[idx])
        {
            return true;
        }
        temp[idx] = true;
    }
    return false;
}

void tag(string s)
{
    for (char ch : s)
    {
        int idx = ch - 'a';
        used[idx] = true;
    }
}

void removetag(string s)
{
    for (char ch : s)
    {
        int idx = ch - 'a';
        used[idx] = false;
    }
}

void backtracing(int n, vector<string> &arr, int cur, int startindex, int &ans)
{
    ans = max(ans, cur);
    if (startindex >= n)
    {
        return;
    }

    for (int i = startindex; i < n; i++)
    {
        if (!haschar(arr[i]))
        {
            tag(arr[i]);
            backtracing(n, arr, cur + arr[i].length(), i + 1, ans);
            removetag(arr[i]);
        }
        else
        {
            continue;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    backtracing(n, arr, 0, 0, ans);
    cout << ans << endl;
    return 0;
}
