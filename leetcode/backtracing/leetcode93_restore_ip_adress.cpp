#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

vector<string> res;

class Solution
{
public:
    bool isvalid(const string&s,int start,int end)
    {
        if(start>end)
        {
            return false;
        }
        if(s[start]=='0'&&start!=end)
        {
            return false;
        }

        int num = 0;
        for (int i = start; i <= end; i++)
        {
            if(s[i]>'9'||s[i]<'0')
            {
                return false;
            }

            num = num * 10 + (s[i] - '0');
            if(num>255)
            {
                return false;
            }
        }
        return true;
    }

    void backtracing(string&s,int startindex,int&pointcount)
    {
        if(pointcount==3)
        {
            if(isvalid(s,startindex,s.size()-1))
            {
                res.push_back(s);
            }
            return;
        }

        for (int i = startindex; i < s.size();i++)
        {
            if(isvalid(s,startindex,i))
            {
                s.insert(s.begin()+i+1,'.');
                pointcount++;
                backtracing(s, i + 2, pointcount);
                pointcount--;
                s.erase(s.begin()+i+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        res.clear();
        int pointcount = 0;
        backtracing(s, 0, pointcount);
        return res;
    }
};