#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int findreputation(vector<vector<int>> &wb, int n, vector<int> &res, vector<vector<int>> &reference)
{
    for (int i = 0; i < n; i++)
    {
        int ref = wb[i][0];
        int k = wb[i][1];
        for (int j = 0; j < k; j++)
        {
            int now = wb[i][j + 2];
            reference[now].push_back(ref);
            res[now]++;
        }
    }

    int max = 0;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] > res[max])
        {
            max = i;
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> wb(n);
    for (int i = 0; i < n; i++)
    {
        int ref;
        int k;
        cin >> ref >> k;
        wb[i].push_back(ref);
        wb[i].push_back(k);
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            wb[i].push_back(x);
        }
    }

    int maxindex = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < wb[i].size(); j++)
        {
            if (maxindex < wb[i][j])
            {
                maxindex = wb[i][j];
            }
        }
    }

    vector<int> res(maxindex + 1, 0);
    vector<vector<int>> reference(maxindex + 1);

    int tarindex = findreputation(wb, n, res, reference);
    vector<int> target = reference[tarindex];
    sort(target.begin(), target.end());

    target.erase(unique(target.begin(), target.end()), target.end());
    cout << tarindex << endl;
    for (int i = 0; i < target.size(); i++)
    {
        if (i != target.size() - 1)
        {
            cout << target[i] << " ";
        }
        else
        {
            cout << target[i] << endl;
        }
    }
    return 0;
}