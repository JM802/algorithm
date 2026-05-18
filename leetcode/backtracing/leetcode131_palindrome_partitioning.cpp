#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    bool ispalindrome(const string&s,int start,int end)
    {
        for (int i = start,j = end; i < j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
        }
        return true;
    }

    void backtracing(const string&s,int startindex,vector<string>&path,vector<vector<string>>&res)
    {
        if(startindex>=s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = startindex; i < s.size();i++)
        {
            if(ispalindrome(s,startindex,i))
            {
                string substr = s.substr(startindex, i-startindex+1);
                path.push_back(substr);
                backtracing(s, i + 1, path, res);
                path.pop_back();
            }
            else
            {
                continue;
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> path;
        vector<vector<string>> res;
        backtracing(s, 0, path, res);
        return res;
    }
};