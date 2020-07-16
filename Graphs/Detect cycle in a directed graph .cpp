// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool dfs(vector<int> adj[], int i, vector<int>&vis, vector<int>&res)
{
    vis[i]=1;
    res[i]=1;
    for(auto j : adj[i])
    {
        if(vis[j]==0 && dfs(adj,j,vis,res))
        return 1;
        else if(res[j]==true)
        return 1;
    }
    res[i]=0;
    return 0;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<int>visited(V,0);
    vector<int>res(V,0);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==0)
        {
            if(dfs(adj,i,visited,res))
            return true;
        }
    }
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
