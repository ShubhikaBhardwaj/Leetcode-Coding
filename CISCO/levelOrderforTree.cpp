//levelOrder


vector<int> levelOrder(Node* node)
{
  	queue<Node*> q;
    q.push(root);

    vector<int> ans;
    while(q.size()!=0)
    {
        int s=q.size();
        vector<int>subAns;
        while(s--)
        {
            Node *rm=q.front();
            q.pop();

            subAns.push_back(rm->data);

            if(rm->left)
            q.push(rm->left);

            if(rm->right)
            q.push(rm->right);

        }
        for(int i=0;i<subAns.size();i++)
        {
            ans.push_back(subAns[i]);
        }

    }

    return ans;

}