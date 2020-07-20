

void deleteNode(Node *node)
{
    Node* cur=node;

    while(cur->next->next!=NULL)
    {
        cur->data=cur->next->data;
        cur=cur->next;
    }
    Node* rm=cur->next;
    delete rm;
    cur->next=NULL;
       
}