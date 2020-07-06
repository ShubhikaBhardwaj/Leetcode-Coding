
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

/* The function should clone the passed tree and return 
   root of the cloned tree */
Node *cloneLR(Node* tree,unordered_map<Node*,Node*> &m)
{
    if(tree==NULL)
    return NULL;

    Node *node=new Node(tree->data);
    m[tree]=node;

    node->left=cloneLR(tree->left,m);
    node->right=cloneLR(tree->right,m);
    return node;
}

Node *cloneRandom(Node* tree,unordered_map<Node*,Node*> &m)
{
    if(tree==NULL)
    return NULL;

    Node *node=new Node(tree->data);
    m[tree]=node;

    node->left=cloneRandom(tree->left,m);
    node->right=cloneRandom(tree->right,m);
    return node;
}


Node* cloneTree(Node* tree)
{
   if(tree==NULL)return NULL;
   unordered_map<Node*,Node*> m;

   Node* cur=cloneLR(tree,m);
   cur=cloneRandom(tree,m);
   return cur;
}
