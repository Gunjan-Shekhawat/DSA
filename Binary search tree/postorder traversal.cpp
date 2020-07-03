
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
vector <int> postOrder(Node* root)
{
  vector<int>res;
  if(root == NULL)
    return res;
  res = postOrder(root->left);
  vector<int>val = postOrder(root->right);
  res.insert(res.end(),val.begin(),val.end());
  res.push_back(root->data);
  return res;
}
