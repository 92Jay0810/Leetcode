#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        int col = board[0].size();
        // 一樣從邊界去找，若邊界為O 那一定不會被改成X 設為T
        for (int i = 0; i < row; i++)
        {
            capture(board, i, 0);
            capture(board, i, col - 1);
        }
        for (int j = 0; j < col; j++)
        {
            capture(board, 0, j);
            capture(board, row - 1, j);
        }
        // 只要和邊界O相鄰就會是T，也不會被改成X
        // 最後檢查不是T的O 就會是X
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void capture(vector<vector<char>> &board, int r, int c)
    {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 'O')
        {
            return;
        }
        // 只要和邊界O相鄰就會是T，也不會被改成X
        board[r][c] = 'T';
        capture(board, r + 1, c);
        capture(board, r, c + 1);
        capture(board, r - 1, c);
        capture(board, r, c - 1);
    }
};
