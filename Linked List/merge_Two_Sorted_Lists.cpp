//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if((list1!=NULL)&&(list2!=NULL)) //only merge if both are non empty list
        {
            if(list1->val > list2->val) //swap => two lists will be merged in list1, so this solution will work only if list1 is the smaller list
            {
                ListNode* temp = list1;
                list1 = list2;
                list2 = temp;
            }
        ListNode* headList1 = list1;
        ListNode* ptrNext1 = list1->next; //point the node next to current node of list1
        ListNode* ptrNext2 = list2->next; //point the node next to current node of list1 

        while((list1->next!= NULL)&&(list2!=NULL))
        {
            if((list2->val==list1->val)||((list2->val>list1->val)&&(list2->val<ptrNext1->val)))
            {
                list1->next=list2;
                list2->next=ptrNext1;
                //to place each node of list2 in list 1, only move to next node of list2 when a node from list2 is placed at correct position of list1 (sorted) 
                if(ptrNext2!=NULL) //end of list2
                {
                list2=ptrNext2; //update: point to the current first node of list2
                ptrNext2=list2->next; 
                }
                else
                {
                    list2=NULL;
                }
            }
            list1 = list1->next;
            ptrNext1=list1->next; 
        }
       if(list2!=NULL) //if list2 is not empty, then append the remaining nodes of list2 to list1
       {
        list1->next = list2;
       }
       ptrNext1=ptrNext2==list2=NULL;
       delete ptrNext1;
       delete ptrNext2;
       delete list2;
       return headList1;    
    }
    else //handle boundary case: atleast one list is empty
    {
        if(list1!=NULL)
          return list1;
        else
          return list2;
    }
    }
};