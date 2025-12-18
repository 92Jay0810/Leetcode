#include <unordered_map>
class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {};
};
// 利用map和left right管理頭尾 低成本的實作LRU的get、put
class LRUCache
{
private:
    int cap;
    std ::unordered_map<int, Node *>
        cache;
    Node *right;
    Node *left;
    void remove(Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node *node)
    {
        Node *prev = right->prev;
        prev->next = node;
        node->prev = prev;
        right->prev = node;
        node->next = right;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            remove(node);
            cache.erase(key);
        }
        Node *newNode = new Node(key, value);
        insert(newNode);
        cache[key] = newNode;
        if (cache.size() > cap)
        {
            Node *lru = left->next;
            cache.erase(lru->key);
            remove(lru);
        }
    }
};
