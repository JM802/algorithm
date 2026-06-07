#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

vector<vector<int>> res;

bool isvalid(int k, int cur, vector<int> &path)
{
    for (int i = 0; i < cur; i++)
    {
        if (path[i] == k)
        {
            return false;
        }
        if ((cur - i) == abs(k - path[i]))
        {
            return false;
        }
    }
    return true;
}

void nqueen(int n, int cur, vector<int> &path)
{
    if (cur == n)
    {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isvalid(i, cur, path))
        {
            path[cur] = i;
            nqueen(n, cur + 1, path);
            path[cur] = -1;
        }
    }
}