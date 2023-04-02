//Time complexity: O(n1+n2)
//Space complexity: O(1)

 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* dummy=new ListNode(); //dummy node to handle edge case
        ListNode* merged = dummy; 
        while(list1 && list2){
            if(list1->val <= list2->val)
            {
                merged->next=list1;
                list1 = list1->next;
            }
            else
            {
                merged->next=list2;
                list2 = list2->next;
            }
            merged=merged->next;          
        }
        if (list1)
         merged->next=list1;
        else
         merged->next=list2;
        return dummy->next;
    }