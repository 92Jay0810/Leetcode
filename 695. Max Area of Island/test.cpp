#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int island = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    island = max(island, bfs(grid, i, j));
                }
            }
        }
        return island;
    }
    int bfs(vector<vector<int>> &grid, int r, int c)
    {
        int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int island = 1;
        queue<pair<int, int>> queue;
        queue.push({r, c});
        grid[r][c] = 0;
        while (!queue.empty())
        {
            pair<int, int> node = queue.front();
            queue.pop();
            int row = node.first;
            int col = node.second;
            for (int i = 0; i < 4; i++)
            {
                int temp_row = row + direction[i][0];
                int temp_col = col + direction[i][1];
                // 這邊debug錯在 檢查正確要記得and
                // 還有這題的格子是數字不是char 檢查一直寫成'0'、'1'
                if (temp_row >= 0 && temp_col >= 0 && temp_row < grid.size() && temp_col < grid[0].size() && grid[temp_row][temp_col] == 1)
                {
                    island++;
                    queue.push({temp_row, temp_col});
                    grid[temp_row][temp_col] = 0;
                }
            }
        }
        return island;
    }
};
