#include <iostream>
#include <vector>
using namespace std;
// 另個做法 Disjoint Set Union 可以參考，每個1作為node增加數量， 若相鄰則合併減少數量
// 也要記得BFS的實作方式，用一個queue 改寫為'0'，加入此點入queue初始化 每次檢查queue 拿出來 看四周，可以的點再入queue 改寫。
class Solution
{
    int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>> &grid, int curr_row, int curr_col)
    {
        int row = grid.size();
        int col = grid[0].size();
        // 自己debug 這邊是curr_row/col >=row/col 超出範圍的
        if (curr_row < 0 || curr_col < 0 || curr_row >= row || curr_col >= col || grid[curr_row][curr_col] == '0')
        {
            return;
        }
        // 改完測周圍土地
        grid[curr_row][curr_col] = '0';
        for (int i = 0; i < 4; i++)
        {
            dfs(grid, curr_row + direction[i][0], curr_col + direction[i][1]);
        }
    }
};
