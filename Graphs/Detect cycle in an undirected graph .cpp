// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool dfs(vector<int> g[],int child,vector<int>&vis,int parent)
{
    vis[child]=1;
    for(auto i: g[child])
    {
        if(vis[i]==1 && i!=parent)
        return 1;
        else if(vis[i]==0 && dfs(g,i,vis,child))
        return 1;
         
    }
    return 0;
    
}
bool isCyclic(vector<int> g[], int V)
{
   vector<int>vis(V,0);
   for(int i=0;i<V;i++)
   {
       if(vis[i]==0)
       {
           if(dfs(g,i,vis,-1)==1)
           return true;
       }
   }
   return false;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
