//O(n)
    ListNode* reverseList(ListNode* head) {
        if(head!=NULL) //can't reverse empty array
        {
            if(head->next!=NULL) //only reverse linkedlist with size>1
            {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* front = head -> next;
        while(front!= NULL)
        {
            curr->next = prev;
            prev=curr;
            curr=front;
            front=front->next;
        }
        curr->next=prev;
        head=curr;
        prev=curr=front=NULL;
        delete prev;
        delete curr;
        delete front;
            }
        }
        return head;
        }