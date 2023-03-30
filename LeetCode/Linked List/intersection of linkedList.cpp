 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A=headA, *B=headB;
        while(A != B)
        {
            A = A==NULL? headB: A->next;
            B = B==NULL? headA: B->next;
        }
        return A;
    }