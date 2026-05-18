#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class person
{
public:
    int bj;
    int gz;
    int diff;

    person(int a, int b, int diff)
    {
        this->bj = a;
        this->gz = b;
        this->diff = diff;
    }
};

bool ischeap(person a, person b)
{
    return a.diff >= b.diff;
}

int gettotalcost(int m, vector<person> &costs)
{
    sort(costs.begin(), costs.end(), ischeap);
    int n = m / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += costs[i].gz;
    }
    for (int i = n; i < m; i++)
    {
        sum += costs[i].bj;
    }
    return sum;
}

int main()
{
    int m;
    cin >> m;
    int bj, gz;
    char c;
    vector<person> costs;
    for (int i = 0; i < m; i++)
    {
        while (cin.peek() != '[')
        {
            cin.ignore();
        }
        cin >> c >> bj >> c >> gz >> c;
        person p(bj, gz, bj - gz);
        costs.push_back(p);
    }
    int res = gettotalcost(m, costs);
    cout << res << endl;
    return 0;
}
