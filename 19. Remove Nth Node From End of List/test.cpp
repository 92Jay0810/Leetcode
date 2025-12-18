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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        // 讓left保持前一個
        ListNode *left = dummy;
        ListNode *right = head;
        // right先跑n個 讓left和right 有n的差距
        while (n > 0)
        {
            right = right->next;
            n--;
        }
        // right跑到end left跑到n-1
        while (right != nullptr)
        {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummy->next;
    }
};
