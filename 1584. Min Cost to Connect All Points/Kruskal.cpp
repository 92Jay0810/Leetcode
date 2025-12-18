#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
// Kruskal 都會用DSU，避免重複的點
// 先算完所有邊 在排序，取最小邊
using namespace std;
class DSU
{
public:
    vector<int> parent, size;
    int capacity;
    DSU(int n)
    {
        capacity = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < capacity; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int node)
    {
        if (node != parent[node])
        {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    bool unionNode(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
        {
            return false;
        }
        if (size[pu] > size[pv])
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else
        {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        capacity--;
        return true;
    }
};
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        DSU dsu(points.size());
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        int cost = 0;
        sort(edges.begin(), edges.end());
        // or for (const tuple<int, int, int>& edge : edges)
        // int w = get<0>(edge);
        // int u = get<1>(edge);
        // int v = get<2>(edge);
        for (auto &[w, u, v] : edges)
        {
            if (dsu.unionNode(u, v))
            {
                cost += w;
            }
        }
        return cost;
    }
};
