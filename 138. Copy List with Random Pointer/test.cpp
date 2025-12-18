#include <unordered_map>
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    std::unordered_map<Node *, Node *> copymap;
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        if (copymap.count(head))
        {
            return copymap[head];
        }
        Node *copy = new Node(head->val);
        copymap[head] = copy;
        // 用Recursive 把copy的點 全部放到map
        copy->next = copyRandomList(head->next);
        // 接著 放完後 再去assign random
        copy->random = copymap[head->random];
        return copy;
    }
};