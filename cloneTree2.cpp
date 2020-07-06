
Node* cloneLR(Node* tree)
{
    if(tree==NULL)
    return NULL;
    
    Node *cl=cloneLR(tree->left);
    Node* cr=cloneLR(tree->right);

    Node *NN=new Node(tree->data);

    NN->left=cl;
    NN->right=NULL;

    tree->left=NN;
    tree->right=cr;

    return tree;

}


void cloneRandom(Node* tree)
{
    if(tree==NULL)
    return;
    
    tree->left->random=tree->random->left;

    cloneRandom(tree->left->left);
    cloneRandom(tree->right);

}

Node* detachTree(Node *tree)
{
  if(tree==NULL)return NULL;

   Node* l =detachTree(tree->left->left);
   Node* r =detachTree(tree->right);

   tree->left=l;
   tree->right=r;
   tree->left->left=l->left;
   tree->left->right=r->right;
 
   return tree;
}


Node* cloneTree(Node* tree)
{  if(tree==NULL)return NULL;
    Node *cur=cloneLR(tree);
    cloneRandom(tree);
    tree=detachTree(tree);

    return tree->left;
}
