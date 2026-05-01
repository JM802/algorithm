#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

bool iscontained(int c1, int c2, int n, const vector<int> &weights)
{
    int sum = 0;
    for (int w : weights)
    {
        sum += w;
    }

    vector<int> dp(c1 + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = c1; j >= weights[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + weights[i]);
        }
    }
    return c2 >= sum - dp[c1];
}

int main()
{
    string line;
    string temp;

    getline(cin, line);
    stringstream ss(line);
    getline(ss, temp, ',');
    int c1 = stoi(temp);
    getline(ss, temp, ',');
    int c2 = stoi(temp);

    getline(cin, line);
    stringstream ss1(line);
    getline(ss1, temp);
    int n = stoi(temp);

    vector<int> weights;
    getline(cin, line);
    stringstream ss2(line);
    while (getline(ss2, temp, ','))
    {
        weights.push_back(stoi(temp));
    }

    bool res = iscontained(c1, c2, n, weights);
    cout << (res ? "true" : "false") << endl;
    return 0;
}