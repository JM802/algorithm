#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>> &obstacleGrid)
    {
        if (i >= m || j >= n || obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        int res = dfs(i + 1, j, m, n, obstacleGrid) + dfs(i, j + 1, m, n, obstacleGrid);
        return res;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int res = dfs(0, 0, m, n, obstacleGrid);
        return res;
    }

    int uniquePathsWithObstacles1(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1)
        {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m&&obstacleGrid[i][0]==0;i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n&&obstacleGrid[0][j]==0;j++)
        {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m;i++)
        {
            for (int j = 1; j < n;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};