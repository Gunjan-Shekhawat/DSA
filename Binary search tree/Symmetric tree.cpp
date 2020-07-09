/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        if(root->left == NULL && root->right==NULL)
            return true;
        queue<TreeNode*>q;
        q.push(root);
        q.push(root);
        while(q.size())
        {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
    
            if(t1->val != t2->val)
                return false;
            if(t1->left && t2->right){ 
                q.push(t1->left);
                q.push(t2->right);
            }
            else if(t1->left || t2->right)
                return false;
            if(t1->right && t2->left){ 
                q.push(t1->right);
                q.push(t2->left); 
            }
            else if(t1->right || t2->left)
                return false;

        }
        return true;
    }
};
