Node* insert(Node* root, int Key)
{
    Node* temp = NULL;
    Node* x = root;
    while(x!=NULL)
    {
        temp = x;
        if(Key<x->data)
            x = x->left;
        else if(Key>x->data)
            x = x->right;
        else
        {
            return root;
        }
    }
    if(temp==NULL)
    {
        root = new Node(Key);
        return root;
    }
    if(temp->data>Key)
    {
        temp->left = new Node(Key);
    }
    else if(temp->data<Key)
    temp->right = new Node(Key);
    return temp;
}
