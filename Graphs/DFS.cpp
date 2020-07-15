vector <int> dfs(vector<int> g[], int N)
{  stack<int> s;
    vector<int> visited(N,0);
    vector<int> res;
    s.push(0);
   res.push_back(0);
    visited[0]=1;
   while(s.size()!=0)
    {
       int vis=s.top();
      
        for(int i=0;i<g[vis].size();i++)
        {
            if(visited[g[vis][i]]!=1)
            {
                res.push_back(g[vis][i]);
                s.push(g[vis][i]);
                visited[g[vis][i]]=1;
               break;
            }
            if(i==g[vis].size()-1)
            {
                s.pop();
            }
         
        }
    }
    return res;
}
