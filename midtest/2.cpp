#include <iostream>
#include <vector>

using namespace std;

bool prune(int sum, int count, int minnum, int n, int k)
{
    int leftsum = n - sum;
    int leftcount = k - count;

    if (leftsum < 0 || leftcount < 0)
    {
        return true;
    }

    if (minnum * leftcount > leftsum)
    {
        return true;
    }

    return false;
}

void backtracing(int n, int k, int sum, int count, int startindex, int &res)
{
    if (prune(sum, count, startindex, n, k))
    {
        return;
    }
    if (sum == n && count == k)
    {
        res++;
        return;
    }

    for (int i = startindex; i <= n - k + 1; i++)
    {
        sum += i;
        count++;
        backtracing(n, k, sum, count, i, res);
        sum -= i;
        count--;
    }
}

int partition_int(int n, int k)
{
    int res = 0;
    backtracing(n, k, 0, 0, 1, res);
    return res;
}