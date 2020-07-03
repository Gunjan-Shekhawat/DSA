//You are required to complete this method
vector<int> levelOrder(Node* node)
{
    vector<int>res;
    queue<Node*>Q;
    if(node==NULL)
        return res;
    Q.push(node);    
    while(!Q.empty())
    {
        Node* temp = Q.front();
        res.push_back((temp->data));
        Q.pop();
        if(temp->left!=NULL)
            Q.push(temp->left);
        if(temp->right!=NULL)
            Q.push(temp->right);
    }
  return res;
}
