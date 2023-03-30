bool isCircular(struct Node *head)
{
    // An empty linked list is circular
    if (head == NULL)
       return true;
  
    // Next of head
    struct Node *node = head->next;
  
    // This loop would stop in both cases (1) If
    // Circular (2) Not circular
    while (node != NULL && node != head)
       node = node->next;
  
    // If loop stopped because of circular
    // condition
    return (node == head);
}