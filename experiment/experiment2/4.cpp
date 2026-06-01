#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int getres(int n,int d[])
{
    int ans = d[0];
    for (int i = 1; i <n;i++)
    {
        if(d[i]>d[i-1])
        {
            ans += d[i] - d[i - 1];
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int* d = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    cout << getres(n, d) << endl;
    return 0;
}
