/*
Geek Land has a population of N people and each peron's ability to rule the town is measured by a numeric value X. The two people that can together rule Geek Land must be compatible with each other ie- the sum of digits of their ability X must be equal. Their combined ability should be maximum amongst all the possible pairs of people. Find the combined ability of the Ruling Pair.

Input:
First line of input contains number of testcases T. For each testcase, there will be 2 lines. First line contains N which denoted the number of people in Geek Land. Second line contains N space separated integers denoting each person's ability X.

Output:
Print the combined ability of the Ruling Pair. If no such pair is possible print -1.

Your Task:
Complete the function RulingPair() which takes, the list of each person's ability, arr[] and N as inputs and returns the combined ability of the Ruling Pair. Return -1 if no such pair is possible. 

Constraints:
1 <= T <= 100
1 <= N <= 10^5
1 <= arr[i] <= 10^9

Example:
Sample Input:
2
5
55 23 32 46 88
4
18 19 23 15

Sample Output:
101
-1 
*/


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std; 

 // } Driver Code Ends


//User function Template for C++

int sumof(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int RulingPair(vector<int> arr, int n) 
{
    // code here
    int res=-1;
    map<int,int> m;
    for(int i=0;i<n;i++){
        int curr=sumof(arr[i]);
        if(m.find(curr)!=m.end()){
            res=max(res,arr[i]+m[curr]);
            m[curr]=max(arr[i],m[curr]);
        }
        else{
            m[curr]=arr[i];
        }
    }
    return res;
}

// { Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		cout << RulingPair(arr,n)<<"\n";
	}
	return 0; 
} 

  // } Driver Code Ends
