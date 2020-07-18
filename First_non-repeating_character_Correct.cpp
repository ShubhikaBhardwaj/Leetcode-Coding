//First non-repeating character in a stream

#include<iostream>

using namespace std;

class Node
{  public:
    char data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }


};

void addNode(Node **head,Node** tail,int data)
{
  Node *node=new Node(data);

    if(*head==NULL)
    {
       *head=node;
       *tail=node;
    }

    else
    {   node->prev=*tail;
        *tail->next=node;
        *tail=node;
    }

}

void removeNode(Node **head,Node** tail,int data)
{
    if(*head==NULL)
    return;

    if(*head==*tail)
    {
        *head=NULL;
        *tail=NULL;
    }

    else
    {
        Node* ptr=*tail;
        *tail=*tail->prev;
        ptr->prev=NULL;
        delete ptr;
        *tail->next=NULL;
    }
        
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        
        Node* inDLL[256];
        bool Repeated[256];
        Node *head=NULL;
        Node* tail=NULL;

        for(int i=0;i<256;i++)
            {Repeated[i]=false;
             inDLL[i]=NULL;
            }

        for(int i=0;i<n;i++)
        {
            char x;
            cin>>x;

            if(!Repeated[x])
            {
                if(inDLL[x]==NULL)
                {
                    addNode(&head,&tail,x);
                    inDLL[x]=tail;
                }

                else
                {
                    removeNode(&head,&tail,x);
                    inDLL[x]=NULL;
                    Repeated[x]=true;
                }
                
            }

                    
                if(head!=NULL)
                cout<<head->data<<" ";

                else 
                cout<<"-1 ";
            

        }


        cout<<endl;
    }
    
    return 0;
}

