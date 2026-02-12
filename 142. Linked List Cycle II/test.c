struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            break;
        }
    }
    // NO cycle
    if(fast ==NULL || fast -> next == NULL) return NULL;
    
    slow = head;
    while(fast != slow){
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}
// head ---- a ----> 入口 ---- b ----> 相遇點 ---- c ----> 回到入口
/*設：
a = head 到 cycle 入口的距離 b = 入口到第一次相遇點的距離
c = cycle 剩下的距離 cycle 長度 = b + c*/
/*因為 fast 比 slow 多走整數圈：2k - k = n * cycle_length
所以：k = n(b + c)*/
/*之後slow 從 head 出發和相遇點的差距：k = a + b
因為會相遇所以等式成立 a + b = n(b + c)
整理一下： a = n(b + c) - b
a = (n-1)(b+c) + c 因此a = (n-1)(cycle) + c
意思是：a 和 c 在 cycle 上是等距的（差整數圈） a ≡ c (mod cycle) */
