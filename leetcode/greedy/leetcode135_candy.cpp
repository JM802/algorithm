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
    int candy(vector<int> &ratings)
    {
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            int j = i;
            if (ratings[j] - ratings[j - 1] > 0)
            {
                candy[j] = candy[j - 1] + 1;
            }
            while (j > 0 && ratings[j] - ratings[j - 1] < 0)
            {
                candy[j - 1] = max(candy[j] + 1, candy[j - 1]);
                j--;
            }
        }
        int res = 0;
        for (int i = 0; i < candy.size(); i++)
        {
            res += candy[i];
        }
        return res;
    }

    int candy1(vector<int> &ratings)
    {
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] - ratings[i - 1] > 0)
            {
                candy[i] = candy[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        int res = 0;
        for (int i = 0; i < candy.size(); i++)
        {
            res += candy[i];
        }
        return res;
    }
};