// { Driver Code Starts
#include <bits/stdc++.h>
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

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topview(struct Node *root, int height,int hd,map<int,pair<int,int>>&m)
{
    if(root == NULL)
    return;
    if(m.find(hd)==m.end())
    {
        m[hd] = make_pair(root->data,height);
    }
    else
    {
        pair<int,int>p = (m.find(hd))->second;
        if(p.second>height)
        {
            m.erase(hd);
            m[hd] = make_pair(root->data,height);
        }
    }
    topview(root->left,height+1,hd-1,m);
    topview(root->right,height+1,hd+1,m);
    
}
void topView(struct Node *root)
{
    map<int,pair<int,int>>m;
    topview(root,0,0,m);
    for(map<int,pair<int,int>>:: iterator i = m.begin();i!=m.end();i++)
    cout<<(i->second).first<<" ";
}


