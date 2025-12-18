#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    // 可以另外寫個Dijkstra 只要做好minheap和visited 陣列orSet 每次從heap拿出來 更新edge 放入heap
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // 題目給的都是1~n 自己做index校正
        vector<int> dist(n, INT_MAX);
        // 初始點為0
        dist[k - 1] = 0;
        // 最後一個點不用做
        for (int i = 0; i < n; i++)
        {
            for (vector<int> &time : times)
            {
                int u = time[0] - 1;
                int v = time[1] - 1;
                int w = time[2];
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = max(result, dist[i]);
        }
        return result == INT_MAX ? -1 : result;
    }
};
