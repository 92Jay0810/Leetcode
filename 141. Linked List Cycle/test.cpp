#include <iostream>
#include <unordered_set>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        std::unordered_set<ListNode *> check;
        ListNode *curr = head;
        while (curr)
        {
            if (check.find(curr) != check.end())
            {
                return true;
            }
            check.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};
