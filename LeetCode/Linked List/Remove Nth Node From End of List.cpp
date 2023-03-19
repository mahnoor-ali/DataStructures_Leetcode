class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *ptr1 = head, *ptr2 = head, *prev = nullptr;
    for(int i=0; i<n; i++)
        ptr1 = ptr1->next;
    while(ptr1) {
        ptr1 = ptr1->next;
        prev = ptr2;
        ptr2 = ptr2->next;
    }
    if(prev == nullptr) {
        head = head->next;
        delete ptr2;
    } else if(ptr2) {
        prev->next = ptr2->next;
        delete ptr2;
    }
    return head;
}
};