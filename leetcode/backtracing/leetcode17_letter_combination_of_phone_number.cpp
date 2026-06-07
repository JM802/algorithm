#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;
string path;
string lettermap[10] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"};

class Solution
{
public:
    void getlettercombination(string digits,int index)
    {
        if(index==digits.size())
        {
            res.push_back(path);
            return;
        }
        int mapindex = digits[index] - '0';
        string letter = lettermap[mapindex];
        for (int i = 0; i < letter.size();i++)
        {
            path.push_back(letter[i]);
            getlettercombination(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        path.clear();
        getlettercombination(digits, 0);
        return res;
    }
};