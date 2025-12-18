#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        int time = 0;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (fresh > 0 && !q.empty())
        {
            // 每一輪用壞掉的水果去傳播
            int length = q.size();
            for (int k = 0; k < length; k++)
            {
                pair<int, int> node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;
                // 忘記做四個方向的傳播
                for (pair<int, int> &direction : directions)
                {
                    int curr_row = r + direction.first;
                    int curr_col = c + direction.second;
                    if (curr_row >= 0 && curr_col >= 0 && curr_row < row && curr_col < col && grid[curr_row][curr_col] == 1)
                    {
                        grid[curr_row][curr_col] = 2;
                        // debug 忘記減掉fresh
                        fresh--;
                        q.push({curr_row, curr_col});
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
