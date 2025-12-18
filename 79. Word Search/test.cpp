#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
    int row = 0, col = 0;
    // 原本用set和pair 但是count和earse太慢，改用修改原表，代表當前的開頭已訪問過
    // set<pair<int, int>> path;

    // 另個做法是visited array，把當下開頭節點下個flag 表示訪問過   vector<vector<bool>> visited;

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        row = board.size();
        col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string word, int r, int c, int i)
    {
        if (i == word.length())
        {
            return true;
        }
        if (r < 0 || c < 0 || r >= row || c >= col || word[i] != board[r][c])
        {
            // path.count({r, c} 也是條件之一 代表已訪問過的開頭節點，但太慢
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        // path.insert({r, c});
        bool result = dfs(board, word, r - 1, c, i + 1) || dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r, c - 1, i + 1) || dfs(board, word, r, c + 1, i + 1);
        // path.erase({r, c});
        board[r][c] = temp;
        return result;
    }
};
