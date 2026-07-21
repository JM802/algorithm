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
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = g.size() - 1;
        int j = s.size() - 1;

        while (i >= 0)
        {
            if (j >= 0 && s[j] >= g[i])
            {
                j--;
                res++;
            }
            i--;
        }
        return res;
    }
};