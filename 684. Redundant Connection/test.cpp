#include <iostream>
#include <vector>
using namespace std;
class DSU
{
public:
    int component;
    vector<int> parent, size;
    DSU(int n)
    {
        component = n;
        // 因此此題的index 是1~n 所以用n+1去resize;
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < component; i++)
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
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        DSU dsu(edges.size());
        for (vector<int> edge : edges)
        {
            if (!dsu.unionNode(edge[0], edge[1]))
            {
                return {edge[0], edge[1]};
            }
        }
        return {};
    }
};
