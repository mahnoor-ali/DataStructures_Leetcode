    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }
        //dummy node previous to head node to handle edge cases in a generalized solution
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* leftPrev = dummy;

        for (int i = 1; i < left; i++) {
            leftPrev = leftPrev->next; //leftPrev: node previous to left node 
        }

        ListNode* curr = leftPrev->next; //left node (where reversal begins)
        ListNode* prev = NULL; //node previous to "curr" node

        //at the end of this loop: curr points at node next to "right" node. curr will be used to link the unlinked list to its head and last node
        for (int i = 0; i < (right-left+1); i++) {
            ListNode* nextPtr = curr->next; //to avoid error bcz on 1st iteration prev=NULL, so curr->next is a null pointer
            curr->next = prev;
            prev = curr;
            curr=nextPtr;
        }
        leftPrev->next->next = curr; // leftPrev->next is 'left' node
        leftPrev->next=prev;

        return dummy->next; //dummy was pointed at head node
    }