/*
Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

Input:
First line contains number of test cases T.  Each test case have one line string S of character '(' and ')' of length  N.

Constraints:
1 <= T <= 500
1 <= N <= 105

Example:
Input:
2
((()
)()())

Output:
2
4

Explanation:
Testcase 1: Longest valid balanced parantheses is () and its length is 2.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    stack<int>st;
	    st.push(-1);
	    string s;
	    cin>>s;
	    int maxm=-1;
	    for(int i=0;i<s.size();i++)
	    {
    	    if(s[i]=='(')
    	    st.push(i);
    	    else
    	    {
    	        st.pop();
    	    if(st.empty())
    	    {
    	        st.push(i);
    	    }
    	    else 
    	    {
    	        maxm = max(maxm, i-st.top());
    	    }
    	    }
    	    
	    }
	    cout<<maxm<<endl;
	}
	return 0;
}
