// time complexity: O(n), space complexity: O(1).

// 2 possible RELATIONs bw slow and fast ptrs
/* 
Even size of list:
Slow-> 1st element of 2nd half
fast: null

ODD size of list:
slow-> mid
fast-> last node(i.e before null)
*/
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Find the middle of the linked list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Ignore the middle node if the linked list has an odd number of nodes
    if (fast != NULL) {
        slow = slow->next;
    }

    // Reverse the second half of the linked list
    slow = reverseList(slow);

    // Compare the first half and the reversed second half of the linked list
    while (slow != NULL) {
        if (head->val != slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

ListNode* reverseList(ListNode* head) {
    // Reverse the linked list using a three-pointer approach
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
