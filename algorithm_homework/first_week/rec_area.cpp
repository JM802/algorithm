#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMaxArea(vector<int> h)
{
    int width;
    int max = INT_MIN;
    int n = h.size();
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = i - 1;
        while (j < n)
        {
            if (h[j] > h[i])
            {
                j++;
            }
            else
            {
                break;
            }
        }

        while (k >= 0)
        {
            if (h[k] > h[i])
            {
                k--;
            }
            else
            {
                break;
            }
        }
        width = j - k - 1;
        if (width * h[i] > max)
        {
            max = width * h[i];
        }
    }
    return max;
}

int getminidx(vector<int> &h, int left, int right)
{
    int min = INT_MAX;
    int index;
    for (int i = left; i <= right; i++)
    {
        if (h[i] < min)
        {
            min = h[i];
            index = i;
        }
    }
    return index;
}

int getmaxarea1(vector<int> &h, int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    int minidx = getminidx(h, left, right);
    int midarea = h[minidx] * (right - left + 1);
    int leftarea = getmaxarea1(h, left, minidx - 1);
    int rightarea = getmaxarea1(h, minidx + 1, right);
    int res = max(midarea, leftarea, rightarea);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> h;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        h.push_back(num);
    }
    int max = getMaxArea(h);
    cout << max << endl;
    return 0;
}