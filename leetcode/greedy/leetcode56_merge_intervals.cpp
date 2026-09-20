#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        int j = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0]<=intervals[i-1][1])
            {
                res[j][1] = max(intervals[i][1], intervals[i - 1][1]);
                intervals[i][0] = min(intervals[i][0], intervals[i - 1][0]);
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
            }
            else
            {
                j++;
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

    vector<vector<int>> merge1(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= res.back()[1])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};