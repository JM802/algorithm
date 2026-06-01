#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int getmax(vector<int>&nums,int n)
{
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int ans = dp[0];

    for (int i = 1; i < n;i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        ans = max(dp[i], ans);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int res = getmax(nums, n);
    cout << res << endl;
    return 0;
}