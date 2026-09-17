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
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return true;
        }

        int cover = 0;
        for (int i = 0; i <= cover; i++)
        {
            cover = max(cover, i + nums[i]);
            if (cover == nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};