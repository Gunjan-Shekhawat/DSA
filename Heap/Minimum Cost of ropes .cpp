/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N where N is the number of ropes. The second line of each test case contains N input L[i],length of ropes.

Output:
For each testcase, print the minimum cost to connect all the ropes.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ L[i] ≤ 106

Example:
Input:
2
4
4 3 2 6
5
4 2 7 6 9

Output:
29
62
*/
#include <bits/stdc++.h>
using namespace std;
long min_cost(int arr[], int n) 
{ 
    // create min priority_queue
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n); 
      long res = 0; 
      while (pq.size() > 1) { 
        int first = pq.top(); 
        pq.pop(); 
        int second = pq.top(); 
        pq.pop(); 
        res += first + second; 
        pq.push(first + second); 
    } 
  
    return res; 
} 

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    cout<<min_cost(arr,n)<<endl;
	}
	return 0;
}
