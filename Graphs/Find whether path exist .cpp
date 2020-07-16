#include <bits/stdc++.h>
using namespace std;

int dfs(int i,int j,vector<vector<int>>&mat,vector<vector<int>> &vis)
{
    int n=mat.size();
    if(i<0 || j<0 ||i>=n || j>=n)
        return 0;

    vis[i][j]=1;
    if(i>0 && i<n && j>=0 && j<n && mat[i-1][j]==2)
        return 1;
    if(i>=0 && i<n && j>0 && j<n && mat[i][j-1]==2)
        return 1;
    if(i>=0 && i<n-1 && j>=0 && j<n && mat[i+1][j]==2)
        return 1;
    if(i>=0 && i<n && j>=0 && j<n-1 && mat[i][j+1]==2)
        return 1;


if(i>0 && i<n && j>=0 && j<n && !vis[i-1][j] && (mat[i-1][j]==3 ) && dfs(i-1,j,mat,vis))
        return 1;
if(i>=0 && i<n && j>0 && j<n && !vis[i][j-1] && (mat[i][j-1]==3 ) && dfs(i,j-1,mat,vis))
        return 1;
if(i>=0 && i<n-1 && j>=0 && j<n && !vis[i+1][j] && (mat[i+1][j]==3 ) && dfs(i+1,j,mat,vis))
        return 1;
if(i>=0 && i<n && j>=0 && j<n-1 && !vis[i][j+1] && (mat[i][j+1]==3 ) && dfs(i,j+1,mat,vis))
        return 1;

return 0;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,y;
	    cin>>n;
	    vector<vector<int>>v(n,vector<int>(n,0));
	    vector<vector<int>>vis(n,vector<int>(n,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>v[i][j];
	            if(v[i][j]==1)
	            x = i,y=j;
	        }
	    }
	    cout<<dfs(x,y,v,vis)<<endl;
	}
	return 0;
}
