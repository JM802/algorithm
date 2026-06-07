#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

vector<vector<int>> res;
vector<vector<int>> A;
int min_len = INT_MAX;
int n;
int t;

void shortestpath(vector<int> &path, int cur, int cur_len, vector<bool> &visited)
{
    if (cur_len > min_len)
    {
        return;
    }

    if (cur == t)
    {
        if (cur_len < min_len)
        {
            min_len = cur_len;
            res.clear();
            res.push_back(path);
            return;
        }
        else if (cur_len == min_len)
        {
            res.push_back(path);
            return;
        }
    }
    for (int next = 0; next < n; next++)
    {
        if (A[cur][next] != INT_MAX && !visited[next])
        {
            path.push_back(next);
            visited[next] = true;
            shortestpath(path, next, cur_len + A[cur][next], visited);
            path.pop_back();
            visited[next] = false;
        }
    }
}
