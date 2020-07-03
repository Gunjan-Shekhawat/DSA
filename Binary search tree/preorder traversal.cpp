struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

vector <int> preorder(Node* root)
{
  vector<int>res;
  if(root==NULL)
  return res;
  res.push_back(root->data);
  vector<int>val = preorder(root->left);
  res.insert(res.end(),val.begin(),val.end());
  vector<int>right = preorder(root->right);
  res.insert(res.end(),right.begin(),right.end());
  return res;
}
