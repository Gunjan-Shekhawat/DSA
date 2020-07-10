// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
void bottomview(Node *root,int height,int hd,map<int,pair<int,int>>&m)
{
    if(root==NULL)
    return;
    
    if(m.find(hd)==m.end())
    {
        m[hd] = make_pair(root->data,height);
    }
    else
    {
        pair<int,int>p = (m.find(hd))->second;
        if(p.second<=height)
        {
            m.erase(hd);
            m[hd] = make_pair(root->data,height);
        }
    }
    bottomview(root->left, height+1, hd-1, m);
    bottomview(root->right, height+1, hd+1, m);
}
vector <int> bottomView(Node *root)
{
   map<int,pair<int,int>>m;
   bottomview(root,0,0,m);
   vector<int>v;
   for(map<int,pair<int,int>>:: iterator it = m.begin();it!=m.end();it++)
   {
       v.push_back((it->second).first);
   }
   return v;
}

// or

void bottomView(Node *root) 
{ 
    if (root == NULL) 
        return; 
  
    // Initialize a variable 'hd' with 0 
    // for the root element. 
    int hd = 0; 
  
    // TreeMap which stores key value pair 
    // sorted on key value 
    map<int, int> m; 
  
    // Queue to store tree nodes in level 
    // order traversal 
    queue<Node *> q; 
  
    // Assign initialized horizontal distance 
    // value to root node and add it to the queue. 
    root->hd = hd; 
    q.push(root);  // In STL, push() is used enqueue an item 
  
    // Loop until the queue is empty (standard 
    // level order loop) 
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        q.pop();   // In STL, pop() is used dequeue an item 
  
        // Extract the horizontal distance value 
        // from the dequeued tree node. 
        hd = temp->hd; 
  
        // Put the dequeued tree node to TreeMap 
        // having key as horizontal distance. Every 
        // time we find a node having same horizontal 
        // distance we need to replace the data in 
        // the map. 
        m[hd] = temp->data; 
  
        // If the dequeued node has a left child, add 
        // it to the queue with a horizontal distance hd-1. 
        if (temp->left != NULL) 
        { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        } 
  
        // If the dequeued node has a right child, add 
        // it to the queue with a horizontal distance 
        // hd+1. 
        if (temp->right != NULL) 
        { 
            temp->right->hd = hd+1; 
            q.push(temp->right); 
        } 
    } 
  
    // Traverse the map elements using the iterator. 
    for (auto i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " "; 
}
