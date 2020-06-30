/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the size of the array. The second line of each test case contains N input C[i].

Output:
For each testcase, print the span values for all days.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 200
1 ≤ C[i] ≤ 800

Example:
Input:
2
7
100 80 60 70 60 75 85
6
10 4 5 90 120 80

Output:
1 1 1 2 1 4 6
1 1 2 4 5 1

 
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    stack<ll>s;
	    ll arr[n],b[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    s.push(0);
	    b[0]=1;
	    for(int i=1;i<n;i++)
	    {
	        while (!s.empty() && arr[s.top()] <= arr[i]) 
                s.pop(); 
            
            b[i] = (s.empty()) ? (i + 1) : (i - s.top()); 
            s.push(i); 
	    }
	    for(int i=0;i<n;i++)
	    cout<<b[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
