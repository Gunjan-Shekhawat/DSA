
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */


// Return a vector containing the inorder traversal of the tree
vector<int> inOrder(Node* root)
{
  vector<int>res;
  if(root == NULL)
  return res; 
  res = inOrder(root->left);
  res.push_back(root->data);
  vector <int> right = inOrder(root->right);
  res.insert(res.end(),right.begin(),right.end());
  return res;
}
