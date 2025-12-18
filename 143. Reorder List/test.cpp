
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        // 確保有三個才能做
        if (!head || !head->next || !head->next->next)
        {
            return;
        }
        // 用快慢指標 找中間點 slow
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        // 幫中間點做切割
        slow->next = nullptr;
        // 之後 後半的list 做reverse list 給prev當頭
        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // 做交叉合併
        ListNode *first = head;
        ListNode *second = prev;

        while (second)
        {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            if (!first)
                break;
            second = temp2;
        }
    }
};
