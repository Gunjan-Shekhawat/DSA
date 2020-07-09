/*
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

Input Format:
The first line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.
There are multiple test cases. For each test case, the function will be called individually.

Output Format:
For each testcase, in a new line, print the maximum possible sum between two leaf nodes.

Your Task:
Complete the function maxPathSum() that returns the maximum sum from one leaf to another.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

Constraints:
1 <=T <= 100
3 <= N <= 104
-1000 <= Data on Node <= 1000

Example:
Input:
2
3 4 5 -10 4
-15 5 6 -8 1 3 9 2 -3 N N N N N 0 N N N N 4 -1 N N 10 N

Output:
16
27

Explanation:
Testcase 2: The maximum possible sum from one leaf node to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)
*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int maxPathSum(Node *);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << maxPathSum(root) << "\n";
    }
    return 0;
}// } Driver Code Ends


/*
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
int maxsum(Node* root, int &res)
{
    if(root == NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return root->data;
    
    int ls = maxsum(root->left,res);
    int rs = maxsum(root->right,res);
    
    if(root->left && root->right)
    {
        res = max(res, ls+rs+root->data);
        
        return max(ls,rs)+root->data;
    }
    
    if(root->left)
        return ls+root->data;
    else
        return rs+root->data;
}
int maxPathSum(Node* root)
{ 
    int res = INT_MIN;
    int k =  maxsum(root,res);
    return res;
}
