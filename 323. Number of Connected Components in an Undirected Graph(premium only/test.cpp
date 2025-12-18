#include <iostream>
#include <vector>
using namespace std;
// 這題同樣可以用dfs、bfs， 用一個visit array， for_loop:只要找到一個沒訪問過 就加1 然後bfs/dfs
class DSU
{
public:
    int component;
    vector<int> parent, size;
    DSU(int n)
    {
        component = n;
        parent.resize(n);
        size.resize(n);
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
    int countComponents(int n, vector<vector<int>> &edges)
    {
        DSU dsu(n);
        for (vector<int> edge : edges)
        {
            dsu.unionNode(edge[0], edge[1]);
        }
        return dsu.component;
    }
};
