class Node
{
    int val;
    Node* next;
};
 
void printReverse(Node* head)
{
    if (head == NULL)
    return;
    printReverse(head->next);
    cout << head->data << " ";
}