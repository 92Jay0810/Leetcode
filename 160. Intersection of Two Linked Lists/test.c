struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* pa = headA;
    struct ListNode* pb = headB;
    while(pa != pb){
        pa = (pa == NULL) ? headB : pa -> next;
        pb = (pb == NULL) ? headA : pb -> next;
    }
    return pa;
}
// a為A獨有 b為B獨有 c 為共通節點
//pa 走完 A → 改走 B  路徑看作 a -> c -> b -> c
//pb 走完 B → 改走 A  路徑看作 b -> c -> a -> c
//最終兩人都會走到共同的c 節點