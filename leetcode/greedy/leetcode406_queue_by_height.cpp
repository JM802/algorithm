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
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }

        else
        {
            return a[0] > b[0];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> reconstruct_queue;
        for (vector<int> p : people)
        {
            int index = p[1];
            reconstruct_queue.insert(reconstruct_queue.begin() + index, p);
        }
        return reconstruct_queue;
    }

    vector<vector<int>> reconstructQueue1(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> reconstructlist;
        for (vector<int> p : people)
        {
            int index = p[1];
            list<vector<int>>::iterator it = reconstructlist.begin();
            while (index--)
            {
                it++;
            }
            reconstructlist.insert(it, p);
        }
        return vector<vector<int>>(reconstructlist.begin(), reconstructlist.end());
    }
};