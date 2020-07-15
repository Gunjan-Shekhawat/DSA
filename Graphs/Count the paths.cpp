#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,m;
	    cin>>n>>m;
	    vector<vector<int>>v(n);
	    vector<int>visited(n,0);
	    while(m--)
	    {
	        ll a,b;
	        cin>>a>>b;
	        v[a].push_back(b);
	    }
	    ll c,d,count=0;
	    cin>>c>>d;
	    queue<int>q;
	    q.push(c);
	    while(!q.empty())
	    {
	        int k = q.front();
	        q.pop();
	        if(k==d)
	        {
	            count++;
	            continue;
	        }
	        visited[k]=1;
	        for(int i=0;i<v[k].size();i++)
	        {
	            // one vertex not visited twice in a single path 
	            if(visited[v[k][i]]==0)
	            q.push(v[k][i]);
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
