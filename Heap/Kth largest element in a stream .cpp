/*
Given an input stream of n integers, find the kth largest element for each element in the stream.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains two space separated integers k and n . Then in the next line are n space separated values of the array.

Output:
For each test case, in a new line, print the space separated values denoting the kth largest element at each insertion, if the kth largest element at a particular insertion in the stream doesn't exist print -1.

Constraints:
1 <= T <= 100
1 <= K <= n
1 <= n <= 106
1 <= stream[] <= 105

Example:
Input:
2
4 6
1 2 3 4 5 6
1 2
3 4

Output:
-1 -1 -1 1 2 3
3 4
*/



#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t,n,k,i;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        priority_queue <int,vector<int>,greater<int>> pq; //min 
        int A[n];
        for(i=0;i<n;i++) 
        {
            cin>>A[i];
            
            if(pq.size()<k)
            {  
                pq.push(A[i]);
                if(pq.size()==k)
                    cout<<pq.top()<<" ";
                else
                    cout<<"-1 ";
            }
            else if(pq.size()==k && A[i]>pq.top())
            {   
                pq.pop();
                pq.push(A[i]);
                cout<<pq.top()<<" ";
            }
            else if(pq.size()==k && A[i]<=pq.top())
            {
                cout<<pq.top()<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}
