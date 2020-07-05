// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}
// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/


Node *constructTree (int post[], int size)
{
    stack<Node*>s;
    Node* root = new Node(post[size-1]);
    s.push(root);
    for(int i=size-2;i>=0;i--)
    {
        Node* x = new Node(post[i]);
        Node* temp = NULL;
        while(!s.empty() && post[i]<(s.top()->data))
            {
                temp = s.top();
                s.pop();
            }
        if(temp==NULL)
        s.top()->right = x;
        else
        temp->left = x;
        s.push(x);
    }
    return root;
}
