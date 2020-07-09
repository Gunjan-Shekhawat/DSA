/*
Flatten a binary tree into linked list
Given a binary tree, flatten it into linked list in-place. Usage of auxiliary data structure is not allowed. After flattening, left of each node should point to NULL and right should contain next node in preorder.

Examples:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6

Output :
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6

Input :
        1
       / \
      3   4
         /
        2
         \
          5
Output :
     1
      \
       3
        \
         4
          \
           2
            \ 
             5
Simple Approach: A simple solution is to use Level Order Traversal using Queue. In level order traversal, keep track of previous node. 
Make current node as right child of previous and left of previous node as NULL. This solution requires queue, but question asks to solve without additional data structure.

Efficient Without Additional Data StructureRecursively look for the node with no grandchildren and both left and right child in the left sub-tree. 
Then store node->right in temp and make node->right=node->left. Insert temp in first node NULL on right of node by node=node->right. 
Repeat until it is converted to linked list.
*/
/* Program to flatten a given Binary  
   Tree into linked list */
#include <iostream> 
using namespace std; 
  
struct Node { 
    int key; 
    Node *left, *right; 
}; 
  
/* utility that allocates a new Node  
   with the given key  */
Node* newNode(int key) 
{ 
    Node* node = new Node; 
    node->key = key; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
// Function to convert binary tree into 
// linked list by altering the right node 
// and making left node point to NULL 
void flatten(struct Node* root) 
{ 
    // base condition- return if root is NULL 
    // or if it is a leaf node 
    if (root == NULL || root->left == NULL && 
                        root->right == NULL) { 
        return; 
    } 
  
    // if root->left exists then we have  
    // to make it root->right 
    if (root->left != NULL) { 
  
        // move left recursively 
        flatten(root->left); 
     
        // store the node root->right 
        struct Node* tmpRight = root->right; 
        root->right = root->left; 
        root->left = NULL; 
  
        // find the position to insert 
        // the stored value    
        struct Node* t = root->right; 
        while (t->right != NULL) { 
            t = t->right; 
        } 
  
        // insert the stored value 
        t->right = tmpRight; 
    } 
  
    // now call the same function 
    // for root->right 
    flatten(root->right); 
} 
  
// To find the inorder traversal 
void inorder(struct Node* root) 
{ 
    // base condition 
    if (root == NULL) 
        return; 
    inorder(root->left); 
    cout << root->key << " "; 
    inorder(root->right); 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    /*    1 
        /   \ 
       2     5 
      / \     \ 
     3   4     6 */
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(5); 
    root->left->left = newNode(3); 
    root->left->right = newNode(4); 
    root->right->right = newNode(6); 
  
    flatten(root); 
  
    cout << "The Inorder traversal after "
            "flattening binary tree "; 
    inorder(root); 
    return 0; 
} 
Output:
The Inorder traversal after flattening 
binary tree 1 2 3 4 5 6
