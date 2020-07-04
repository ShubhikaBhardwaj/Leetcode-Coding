#include<iostream>
#include<vector>


void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}




int main()
{
    vector<int>arr={25,20,10,5,1,8,12,15,22,36,30,28,40,38,48,45,50};
     
    Node *root;
    root=constructTree(root,arr,0,arr.size()-1);

    display(root); 

    return 0;
}