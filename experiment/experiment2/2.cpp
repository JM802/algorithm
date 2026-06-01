#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int check(int val, vector<int> &real, int n)
{
    vector<int> predict(n + 2, 0);
    predict[1] = val;
    for (int i = 1; i <= n - 1; i++)
    {
        predict[i + 1] = real[i] - predict[i] - predict[i - 1];
        if (predict[i + 1] > 1 || predict[i + 1] < 0)
        {
            return 0;
        }
    }

    predict[n + 1] = real[n] - predict[n] - predict[n - 1];
    if (predict[n + 1] != 0)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> real(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        real[i] = num;
    }
    int res = check(0, real, n) + check(1, real, n);
    cout << res << endl;
    return 0;
}