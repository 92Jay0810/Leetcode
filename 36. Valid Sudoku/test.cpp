#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<char>> row, col;
        // this only can use map，because unorder is base on hash table，only accept int string...
        map<pair<int, int>, unordered_set<char>> square;
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                // important!
                if (board[r][c] == '.')
                {
                    continue;
                }
                // make same squre key
                pair<int, int> squarePair = {r / 3, c / 3};
                if (row[r].count(board[r][c]) || col[c].count(board[r][c]) || square[squarePair].count(board[r][c]))
                {
                    return false;
                }
                row[r].insert(board[r][c]);
                col[c].insert(board[r][c]);
                square[squarePair].insert(board[r][c]);
            }
        }
        return true;
    }
};
