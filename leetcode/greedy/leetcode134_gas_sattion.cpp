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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        for (int i = 0; i < gas.size(); i++)
        {
            int cur = gas[i] - cost[i];
            int index = (i + 1) % gas.size();

            while (cur > 0 && index != i)
            {
                cur += gas[index] - cost[index];
                index = (index + 1) % gas.size();
            }
            if (cur >= 0 && index == i)
            {
                return i;
            }
        }
        return -1;
    }

    int canCompleteCircuit1(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        int cur = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            cur += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if (cur < 0)
            {
                start = i + 1;
                cur = 0;
            }
        }
        if (total < 0)
        {
            return -1;
        }
        return start;
    }
};