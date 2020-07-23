
// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{

    Node* cur=head;
    Node* next=cur->next;
    Node *prev=NULL;

    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }

    return prev;
}

