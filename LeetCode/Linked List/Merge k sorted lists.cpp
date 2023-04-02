/*
This problem can be solved using a divide and conquer approach, where we recursively merge the linked-lists into smaller sub-lists until we are left with only one list.
To do this, use a helper function that takes in two linked-lists and merges them into one sorted list. repeat this process on pairs of linked-lists until we are left with only one list.

Here are the steps to follow:

If the array of linked-lists is empty, return null.
If the array contains only one linked-list, return that list.
Divide the array into two halves and recursively merge each half into one linked-list.
Merge the two resulting linked-lists using the helper function mentioned above.
Return the final merged linked-list.
*/

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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
         return NULL;
        else if(n==1)
         return lists[0];
        
        ListNode* l = mergeTwoLists(lists[0], lists[1]);
        for(int i=2; i<n; i++)
        {
            l = mergeTwoLists(l, lists[i]);
        }
        return l;        
    }