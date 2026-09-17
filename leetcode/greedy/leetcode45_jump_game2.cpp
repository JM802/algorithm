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
    int jump(vector<int> &nums)
    {
        int res = 0;
        int i = 0;
        while (i < nums.size() - 1)
        {
            if (i + nums[i] >= nums.size() - 1)
            {
                res++;
                break;
            }
            int cover = 0;
            int next = i + 1;
            int end = min(i + nums[i], (int)nums.size() - 1);
            for (int j = i + 1; j <= end; j++)
            {
                if (cover < j + nums[j])
                {
                    cover = j + nums[j];
                    next = j;
                }
            }
            res++;
            i = next;
        }
        return res;
    }
};