#include <iostream>
#include <vector>
using namespace std;
// 練習DSU 這題同樣可以BFS 、DFS 只是需要紀錄parent 因為是tree 檢測cycle
class DSU
{
public:
    vector<int> size, parent;
    int component;
    DSU(int n)
    {
        component = n;
        // resize n其實就夠了，因為從0輸入~n-1
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i < component; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int node)
    {
        if (parent[node] != node)
        {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    bool unionNode(int n, int v)
    {
        int np = find(n);
        int vp = find(v);
        if (np == vp)
        {
            return false;
        }
        if (size[np] > size[vp])
        {
            size[np] += size[vp];
            parent[vp] = np;
        }
        else
        {
            size[vp] += size[np];
            parent[np] = vp;
        }
        component--;
        return true;
    }
};
class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        // undirect graph edge > n-1 must have cycle
        if (edges.size() > n - 1)
        {
            return false;
        }
        DSU dsu(n);
        for (vector<int> &edge : edges)
        {
            if (!dsu.unionNode(edge[0], edge[1]))
            {
                return false;
            }
        }
        return dsu.component == 1;
    }
};
