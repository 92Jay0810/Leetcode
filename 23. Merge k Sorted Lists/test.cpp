#include <iostream>
#include <vector>
using namespace std;
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }
        return divide(lists, 0, lists.size() - 1);
    }
    // 利用divide 把lists 變成只有兩個ListNode* 做conquer
    ListNode *divide(vector<ListNode *> &lists, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        if (left == right)
        {
            return lists[left];
        }
        int mid = (left + right) / 2;
        ListNode *leftNode = divide(lists, left, mid);
        ListNode *rightNode = divide(lists, mid + 1, right);
        return conquer(leftNode, rightNode);
    }
    ListNode *conquer(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1)
        {
            curr->next = l1;
        }
        else
        {
            curr->next = l2;
        }
        return dummy->next;
    }
};
