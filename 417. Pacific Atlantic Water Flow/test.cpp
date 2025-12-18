#include <iostream>
#include <vector>
using namespace std;
class Solution
{

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        // 題目是找山頂可以流到海洋的格子
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> pac(row, vector<bool>(col, false));
        vector<vector<bool>> atl(row, vector<bool>(col, false));
        // 反向思考，從top(太平洋) bottom(大西洋) 去傳播 找可以流動到海洋的格子
        for (int c = 0; c < col; c++)
        {
            dfs(heights, pac, 0, c);
            dfs(heights, atl, row - 1, c);
        }
        // 反向思考，從left(太平洋) right(大西洋) 去傳播 找可以流動到海洋的格子
        for (int r = 0; r < row; r++)
        {
            dfs(heights, pac, r, 0);
            dfs(heights, atl, r, col - 1);
        }
        vector<vector<int>> result;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // 兩個同時都有被傳播到，就可以是答案
                if (pac[i][j] && atl[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &occan, int row, int col)
    {
        occan[row][col] = true;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (pair<int, int> direction : directions)
        {
            int curr_row = row + direction.first;
            int curr_col = col + direction.second;
            // 找合理範圍 和沒訪問過的
            // 因為反推，從低處海洋反推到高處山頂，要找curr_row/col 是比較高的
            if (curr_row >= 0 && curr_col >= 0 && curr_row < heights.size() && curr_col < heights[0].size() && !occan[curr_row][curr_col] && heights[row][col] <= heights[curr_row][curr_col])
            {
                dfs(heights, occan, curr_row, curr_col);
            }
        }
    }
};
