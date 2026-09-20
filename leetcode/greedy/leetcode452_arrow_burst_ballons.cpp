#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <list>
using namespace std;
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {

        if (points.size() == 0)
        {
            return 0;
        }

        sort(points.begin(), points.end(), cmp);
        int res = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > points[i - 1][1])
            {
                res++;
            }
            else
            {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return res;
    }
};