/*
Imagine you have a special keyboard with the following keys: 

Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times. 


Example 1:

Input: N = 3
Output: 3
Explaination: Press key 1 three times.

Example 2:

Input: N = 7
Output: 9
Explaination: The best key sequence is 
key 1, key 1, key 1, key 2, key 3,
key4, key 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function optimalKeys() which takes N as input parameter and returns the maximum number of A's that can be on the screen after performing N operations.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)
*/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
//  In general,
//  f(N) = N if N < 7
//       = max{2*f(N-3), 3*f(N-4),..., (N-2)*f(1)}

public:
    unsigned long long int optimalKeys(int N){
    if (N <= 6) 
        return N; 
  
    int screen[N]; 
    int b; 
    int n; 
    for (n = 1; n <= 6; n++) 
        screen[n - 1] = n; 
  
    for (n = 7; n <= N; n++) { 
        screen[n - 1] = 0; 

        for (b = n - 3; b >= 1; b--) { 

            int curr = (n - b - 1) * screen[b - 1]; 
            if (curr > screen[n - 1]) 
                screen[n - 1] = curr; 
        } 
    } 
    return screen[N - 1]; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

