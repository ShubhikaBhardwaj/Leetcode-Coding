//Reverse LevelOrder 

void reversePrint(Node *root)
{
    queue<Node*> q;
    q.push(root);
     
    stack<string> ans;
    while(q.size()!=0)
    {
        int s=q.size();
        string subAns="";
        while(s--)
        {
            Node *rm=q.front();
            q.pop();

            subAns+=rm->data+" ";

            if(rm->left)
            q.push(rm->left);

            if(rm->right)
            q.push(rm->right);

        }


        ans.push_back(subAns);

    }

    while(ans.size()!=0)
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
}