#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	ll t;
	 cin>>t;
	 while(t--)
	 {
	     ll n, m;
	     cin>>n>>m;
	     vector<vector<int>>v(n);
	     while(m--)
	     {
	         ll a,b;
	         cin>>a>>b;
	         v[a].push_back(b);
	         v[b].push_back(a);
	     }
	     for(int i=0;i<n;i++)
	     {
	         cout<<i;
	         for(int j=0;j<v[i].size();j++)
	         cout<<"-> "<<v[i][j];
	         cout<<endl;
	     }
	 }
	return 0;
}
