#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                if (wordset.find(word) != wordset.end() && dp[j])
                {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};