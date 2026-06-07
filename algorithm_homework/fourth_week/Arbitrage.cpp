#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

vector<vector<double>> changes;
vector<int> res;
int n;

// question a
double getmax(int a, int b)
{
    vector<double> maxvol(n, 0.0);
    maxvol[a] = 1.0;
    for (int iter = 1; iter <= n - 1; iter++)
    {
        bool update = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (maxvol[j] < maxvol[i] * changes[i][j])
                {
                    maxvol[j] = maxvol[i] * changes[i][j];
                    update = true;
                }
            }
        }
        if (!update)
        {
            break;
        }
    }
    return maxvol[b];
}

// question b
bool arbitrage()
{
    vector<vector<double>> arbitrage = changes;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (arbitrage[j][k] < arbitrage[j][i] * arbitrage[i][k])
                {
                    arbitrage[j][k] = arbitrage[j][i] * arbitrage[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arbitrage[i][i] > 1 + 1e6)
        {
            return true;
        }
    }
    return false;
}