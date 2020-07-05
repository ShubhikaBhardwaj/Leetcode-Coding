#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    vector<Node *> childs;

    Node(int data)
    {
        this->data = data;
    }
};

Node *createTree(vector<int> &arr)
{
    stack<Node *> st;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int ele = arr[i];
        if (ele == -1)
        {
            Node *node = st.top();
            st.pop();
            st.top()->childs.push_back(node);
        }
        else
            st.push(new Node(ele));
    }

    return st.top();
}

void preOrder(Node *node)
{
    cout << node->data << " ";
    for (Node *child : node->childs)
        preOrder(child);
}

void postOrder(Node *node)
{
    for (Node *child : node->childs)
        postOrder(child);
    cout << node->data << " ";
}

int height(Node *node)
{
    int h = -1;
    for (Node *child : node->childs)
        h = max(h, height(child));

    return h + 1;
}

int size(Node *node)
{
    int sz = 0;
    for (Node *child : node->childs)
        sz += size(child);

    return sz + 1;
}

void display(Node* node){
   
    cout << node->data << " -> ";

    for (Node *child : node->childs)
        cout<<child->data<<" ";

    cout<<endl;
    
    for (Node *child : node->childs)
         display(child);

}

bool find(Node* node,int data){
   
   if(node->data==data)
   return true;

   bool ans=false;

   for(Node *child: node->childs)
      {
          bool cur=find(child,data);
          if(cur==true)
          {  
              return true;
          }

          ans=ans||cur;
      }


   return ans;
}

void levelOrderLineWise(Node* node){

  queue< Node*> q;
  q.push(node);
  int k=0;
  while(q.size()!=0)
  {
    int s=q.size();
    cout<<"Level "<<k<<"->";
    while(s-->0)
    {
     Node* rm=q.front();
     q.pop();

     cout<<rm->data<<" ";
     for(Node *child: rm->childs)
        q.push(child);

    }
   cout<<endl;
   k++;
  }

  cout<<endl;
}


bool nodeToRootPath(Node* node,int data,vector<Node*>&path){

   if(node->data==data)
   { path.push_back(node);
     return true;
   }

   bool ans=false;

   for(Node *child: node->childs)
      {
          bool cur=nodeToRootPath(child,data,path);
          ans=ans||cur;
        }
   
   if(ans==true)
   {
       path.push_back(node);
   }

   return ans;

}

void distanceBetweenTwoNodes(Node* node,int d1,int d2){

}

void solve()
{
    vector<int> arr{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, 120, 140, -1, 150, -1, -1, -1, -1};
    Node *root=createTree(arr);
    //display(root);
    //cout<<find(root,50)<<endl;
    //cout<<find(root,90);
    //levelOrderLineWise(root);
    vector<Node *>path;
    nodeToRootPath(root,140,path);

    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]->data<<" ";
    }
    
    cout<<endl;
}

int main()
{
    solve();
    return 0;
}