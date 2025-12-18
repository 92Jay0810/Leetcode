
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 每次回圈用group區分 0~k-1 並且會有group_prev、group_next 最後一個為kth (index k-1)
        ListNode *dummy = new ListNode(0, head);
        ListNode *group_prev = dummy;
        while (true)
        {
            // 拿當下的group_prev 往後k個 (到group的尾端　kth )
            ListNode *Kth = getKth(group_prev, k);
            if (!Kth)
            {
                break;
            }
            ListNode *group_next = Kth->next;
            ListNode *prev = Kth->next;
            ListNode *curr = group_prev->next;
            // 做reverse
            while (curr != group_next)
            {
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            // 剩下開頭沒有assign好 assign 給kth
            ListNode *temp = group_prev->next;
            group_prev->next = Kth;
            group_prev = temp;
        }
        return dummy->next;
    }
    ListNode *getKth(ListNode *head, int k)
    {
        while (head && k > 0)
        {
            head = head->next;
            k--;
        }
        return head;
    }
};
