#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getscore(vector<int> &nums, int i, int j)
{
    if (i == j)
    {
        return nums[i];
    }

    int left = nums[i] - getscore(nums, i + 1, j);
    int right = nums[j] - getscore(nums, i, j - 1);
    return max(left, right);
}

bool predict_winner(vector<int> &nums, int n)
{
    return getscore(nums, 0, n - 1) >= 0;
}

bool predict_winner1(vector<int> &num, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = num[i];
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = max(num[i] - dp[i + 1][j], num[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
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
    if (predict_winner(nums, n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}