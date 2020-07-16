#include <bits/stdc++.h>
using namespace std;
void floodfill(int x,int y,int k,int val,vector<vector<int>>&v)
{
    if(x<0||y<0||x>=v.size()||y>=v[0].size())
    return;
    if(v[x][y]==val)
    {
        v[x][y]=k;
        floodfill(x-1,y,k,val,v);
        floodfill(x+1,y,k,val,v);
        floodfill(x,y-1,k,val,v);
        floodfill(x,y+1,k,val,v);
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>m>>n;
	    vector<vector<int>>arr(m,vector<int>(n,0));
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	            cin>>arr[i][j];
	    }
	    int x,y,k;
	    cin>>x>>y>>k;
	    int val = arr[x][y];
	    floodfill(x,y,k,val,arr);
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	            cout<<arr[i][j]<<" ";
	    }
	    	       cout<<endl;     

	}
	return 0;
}
