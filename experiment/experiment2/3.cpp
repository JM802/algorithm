#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

double a, b, c, d;

double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

double findres(double l, double r)
{
    while (r - l > 1e-4)
    {
        double mid = (l + r) / 2;
        if (f(l) * f(mid) < 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return l;
}

int main()
{
    cin >> a >> b >> c >> d;
    int count = 0;
    double res[3];
    for (int i = -100; i <= 100; i += 1)
    {
        double l = i;
        double r = i + 1;
        double fl = f(l);
        double fr = f(r);
        if (fl == 0.0)
        {
            res[count++] = l;
        }
        else if (fl * fr < 0)
        {
            res[count++] = findres(l, r);
        }
        if (count == 3)
        {
            break;
        }
    }
    cout << fixed << setprecision(2);
    cout << res[0] << " " << res[1] << " " << res[2] << endl;
    return 0;
}