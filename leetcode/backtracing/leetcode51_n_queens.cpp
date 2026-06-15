#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

vector<vector<string>> res;

class Solution
{
public:
    bool isvalid(vector<string> &chessboard, int n, int row, int column)
    {
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][column] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void backtracing(int n, int row, vector<string> &chessboard)
    {
        if (row == n)
        {
            res.push_back(chessboard);
            return;
        }

        for (int column = 0; column < n; column++)
        {
            if (isvalid(chessboard, n, row, column))
            {
                chessboard[row][column] = 'Q';
                backtracing(n, row + 1, chessboard);
                chessboard[row][column] = '.';
            }
            else
            {
                continue;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        res.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracing(n, 0, chessboard);
        return res;
    }
};