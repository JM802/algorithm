#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> res;

void twoawards(int n, int m, vector<int> &v1, vector<int> &v2)
{
    unordered_set<int> s(v2.begin(), v2.end());
    for (int x : v1)
    {
        if (s.count(x))
        {
            res.push_back(x);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v1.push_back(num);
    }

    for (int j = 0; j < m; j++)
    {
        int num;
        cin >> num;
        v2.push_back(num);
    }

    res.clear();
    twoawards(n, m, v1, v2);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}