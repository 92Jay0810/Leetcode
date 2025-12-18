#include <iostream>
#include <unordered_map>
using namespace std;
class treeNode
{
public:
    unordered_map<char, treeNode *> map;
    bool endofword = false;
};
// Trie
class PrefixTree
{
public:
    treeNode *root;
    // Trie
    PrefixTree()
    {
        root = new treeNode();
    }

    void insert(string word)
    {
        treeNode *curr = root;
        for (char c : word)
        {
            if (curr->map.find(c) == curr->map.end())
            {
                curr->map[c] = new treeNode();
            }
            curr = curr->map[c];
        }
        curr->endofword = true;
    }

    bool search(string word)
    {
        treeNode *curr = root;
        for (char c : word)
        {
            if (curr->map.find(c) == curr->map.end())
            {
                return false;
            }
            curr = curr->map[c];
        }
        return curr->endofword;
    }

    bool startsWith(string prefix)
    {
        treeNode *curr = root;
        for (char c : prefix)
        {
            if (curr->map.find(c) == curr->map.end())
            {
                return false;
            }
            curr = curr->map[c];
        }
        return true;
    }
};
