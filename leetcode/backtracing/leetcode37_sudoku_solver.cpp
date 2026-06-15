#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isvalid(vector<vector<char>> &board, char c, int x, int y)
    {
        for (int row = 0; row < board.size(); row++)
        {
            if (board[row][y] == c)
            {
                return false;
            }
        }

        for (int column = 0; column < board[0].size(); column++)
        {
            if (board[x][column] == c)
            {
                return false;
            }
        }

        int xstartindex = x / 3 * 3;
        int ystartindex = y / 3 * 3;

        for (int i = xstartindex; i < xstartindex + 3; i++)
        {
            for (int j = ystartindex; j < ystartindex + 3; j++)
            {
                if (board[i][j] == c)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool backtracing(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isvalid(board, c, i, j))
                        {
                            board[i][j] = c;
                            bool result = backtracing(board);
                            if (result)
                            {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracing(board);
    }
};