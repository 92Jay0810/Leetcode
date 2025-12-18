#include <vector>
#include <iostream>
#include <queue>
using namespace std;
// 以點為主，每次算邊，找距離最近的邊
// priority_queue 加 visit array
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        vector<bool> visit(n, false);
        minheap.push({0, 0});
        int cost = 0;
        // 數node
        int count = 0;
        while (!minheap.empty() && count < n)
        {
            pair<int, int> node = minheap.top();
            // 嚴重錯誤，忘記pop
            minheap.pop();
            int dist = node.first;
            int u = node.second;
            if (visit[u])
            {
                continue;
            }
            visit[u] = true;
            cost += dist;
            count++;
            // 沒訪問過的點都算距離，利用priority_queue找距離最近的點
            // 利用visit 處理沒算過的點 (類似DSU的功能)
            for (int v = 0; v < n; v++)
            {
                if (!visit[v])
                {
                    int distance = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minheap.push({distance, v});
                }
            }
        }
        return cost;
    }
};
