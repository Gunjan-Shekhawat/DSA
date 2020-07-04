
/*https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1 
 The structure of a BST node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

*/

// The function returns the root of the BST (currently rooted at 'root') 
// after inserting a new Node with value 'Key' into it. Node* insert(Node* root, int Key)
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
