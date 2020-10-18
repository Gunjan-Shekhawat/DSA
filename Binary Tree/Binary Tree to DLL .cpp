Node* previous = NULL;

void BinaryTree2DoubleLinkedList(Node *root, Node **head) 
{ 
    if (root == NULL) return; 
 
    BinaryTree2DoubleLinkedList(root->left, head); 
  
    if (previous == NULL) 
        *head = root; 
    else
    { 
        root->left = previous; 
        previous->right = root; 
    } 
    previous = root; 
    BinaryTree2DoubleLinkedList(root->right, head); 
} 
Node * bToDLL(Node *root)
{
    previous = NULL;
    Node*head = NULL;
    BinaryTree2DoubleLinkedList(root,&head);
    return head;
}
