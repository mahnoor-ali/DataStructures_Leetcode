//using fast and slow pointer. The fast pointer moves two steps at a time and the slow pointer moves one step at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the middle of the list.
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* m=head;        
        while(head && head->next)
        {
            m=m->next;
            head=head->next->next;
        }
        return m;
    }
};