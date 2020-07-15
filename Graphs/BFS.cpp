// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {
queue<int>q;
vector<int>ans;
vector<int>visited(N,0);
q.push(0);
visited[0]=1;
ans.push_back(0);
while(!q.empty())
{
    int k = q.front();
    for(int i=0;i<g[k].size();i++)
    {
        if(visited[g[k][i]]==0){
        ans.push_back(g[k][i]);
        q.push(g[k][i]);
        visited[g[k][i]] = 1;
        }
    }
    q.pop();
}
return ans;
}
