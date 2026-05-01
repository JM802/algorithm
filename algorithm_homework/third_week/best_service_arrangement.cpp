#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

double besttotaltime(int n, int s, vector<int> &times)
{
    sort(times.begin(), times.end());
    vector<int> waittime(s, 0);
    double totaltime = 0;

    for (int i = 0; i < n; i++)
    {
        int index = i % s;
        waittime[index] += times[i];
        totaltime += waittime[index];
    }

    return totaltime;
}

int main()
{

    string line;
    string temp, temp1, temp2;
    getline(cin, line);
    stringstream ss(line);
    getline(ss, temp, ',');
    int n = stoi(temp);
    getline(ss, temp1, ',');
    int s = stoi(temp1);

    vector<int> times;
    getline(cin, line);
    stringstream ss1(line);
    while (getline(ss1, temp2, ','))
    {
        times.push_back(stoi(temp2));
    }

    double totaltime = besttotaltime(n, s, times);
    cout << fixed << setprecision(3) << (totaltime / n) << endl;
    return 0;
}