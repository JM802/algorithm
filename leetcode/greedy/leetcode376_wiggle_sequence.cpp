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
    int wiggleMaxLength(vector<int> &nums)
    {
        int res = 1;
        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    up[i] = max(up[i], down[j] + 1);
                }
                else if (nums[i] < nums[j])
                {

                    down[i] = max(down[i], up[j] + 1);
                }
            }
            res = max({res, up[i], down[i]});
        }
        return res;
    }

    int wiggleMaxLength1(vector<int> &nums)
    {
        auto end = unique(nums.begin(), nums.end());
        nums.erase(end, nums.end());
        if (nums.size() <= 2)
        {
            return nums.size();
        }

        int result = 1;
        int prediff = 0;
        int curdiff = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            curdiff = nums[i + 1] - nums[i];
            if ((prediff >= 0 && curdiff < 0) || (prediff <= 0 && curdiff > 0))
            {
                result++;
                prediff = curdiff;
            }
        }
        return result;
    }
};