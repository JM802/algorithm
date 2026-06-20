#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> res;
string path;

void backtracing(int n, int count, int left, int right)
{
    if (count == 2 * n)
    {
        res.push_back(path);
    }

    if (left < n)
    {
        path.push_back('(');
        backtracing(n, count + 1, left + 1, right);
        path.pop_back();
    }

    if (left > right)
    {
        path.push_back(')');
        backtracing(n, count + 1, left, right + 1);
        path.pop_back();
    }
}