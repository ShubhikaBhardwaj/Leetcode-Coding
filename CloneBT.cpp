Node *cloneLR(Node* tree,unordered_map&<Node*,Node*> m)
{
     
     if(tree==NULL)return NULL;

     Node *cur=new Node(tree->data);
     m[tree]=cur;

     cur->left=tree->left?cloneLR(tree->left,m):NULL;
     cur->right=tree->right?cloneLR(tree->right,m):NULL;
     

     return cur;
}

Node *cloneRandom(Node* tree,unordered_map&<Node*,Node*> m)
{
    if(tree==NULL)
    return NULL;

    Node* cur=m[tree];
    cur->random=tree->random;

    cur->left=tree->left?cloneRandom(tree->left,m):NULL;
    cur->right=tree->right?cloneRandom(tree->right,m):NULL;
     

     return cur;

}

Node* cloneTree(Node* tree)
{
   if(tree==NULL)return NULL;

   unordered_map<Node*,Node*> m;
   
   Node* node=cloneLR(tree,m);
   node=cloneRandom(tree,m);

   return node;

}
