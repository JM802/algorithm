#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <utility>
using namespace std;

int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int curx = cur.first;
        int cury = cur.second;

        for (int i = 0; i < 4; i++)
        {
            int newx = curx + direction[i][0];
            int newy = cury + direction[i][1];

            if (newx >= grid.size() || newx < 0 || newy >= grid[0].size() || newy < 0)
            {
                continue;
            }

            if (!visited[newx][newy] && grid[newx][newy] == 1)
            {
                q.push({newx, newy});
                visited[newx][newy] = true;
            }
        }
    }
}

int main()
{
    int count = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                count++;
                bfs(grid, visited, i, j);
            }
        }
    }
    cout << count << endl;
    return 0;
}