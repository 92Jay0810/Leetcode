#include <iostream>
#include <vector>
#include <map>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
// dfs
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        map<Node *, Node *> old_new;
        return dfs(old_new, node);
    }
    Node *dfs(map<Node *, Node *> &old_new, Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (old_new.count(node))
        {
            return old_new[node];
        }
        Node *new_node = new Node(node->val);
        old_new[node] = new_node;
        for (Node *neigbor : node->neighbors)
        {
            new_node->neighbors.push_back(dfs(old_new, neigbor));
        }
        return new_node;
    }
};
