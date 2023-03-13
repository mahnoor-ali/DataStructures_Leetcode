/*
"hare and tortoise algorithm" --> for detecting a cycle in a linked lis
In a linked list with a cycle, the fast pointer will eventually catch up to the slow pointer. This is because the fast pointer is moving twice as fast as the slow pointer, and since it's an infinite loop, it will eventually meet the slow pointer.
On the other hand, if the linked list does not have a cycle, the fast pointer will eventually reach the end of the list because it's moving twice as fast as the slow pointer. The slow pointer would have already reached the end of the list in this case.
This is why the code uses a while loop to keep moving the pointers until either the fast pointer reaches the end of the list (indicating no cycle) or the slow and fast pointers meet (indicating a cycle).
*/

class Solution {
public:
bool hasCycle(ListNode *head) {
  if (head == NULL || head->next == NULL) return false;

  ListNode *slow = head;
  ListNode *fast = head->next;

  while (fast != NULL && fast->next != NULL) {
    if (slow == fast) return true;
    slow = slow->next;
    fast = fast->next->next;
  }
  return false;
}

};