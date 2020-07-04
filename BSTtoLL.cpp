/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
   Node* fun(Node *node)
   {
       if(node==NULL)
       return node;

       Node *cur;
       cur->left=fun(node->left);

       cur->val=node->val;

       cur->right=fun(node->right);
       return cur;

   }


    Node* treeToDoublyList(Node* root) 
    {

        Node *head=fun(root);
         
        Node *cur=head;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }

        Node *tail=cur;
        tail->right=head;
        head->left=tail;

        return head;
        
    }
};