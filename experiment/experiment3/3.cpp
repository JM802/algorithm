#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int mostbuilding(int n, vector<int> &height)
{
    vector<int> dp_up(n + 1, 1);
    vector<int> dp_down(n + 1, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (height[j] < height[i])
            {
                dp_up[i] = max(dp_up[i], dp_up[j] + 1);
            }
            if (height[j] > height[i])
            {
                dp_down[i] = max(dp_down[i], dp_down[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, max(dp_up[i], dp_down[i]));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    int res = mostbuilding(n, height);
    cout << res << endl;
    return 0;
}