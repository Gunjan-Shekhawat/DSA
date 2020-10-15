/*
Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA*/


#include <iostream>
using namespace std;
void permute(string a, int l, int r)  
{  
    // Base case  
    if (l == r)  
        cout<<a<<" ";  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            swap(a[l], a[i]);  
  
            permute(a, l+1, r);  
  
            swap(a[l], a[i]);  
        }  
    }  
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s,t="";
	    cin>>s;
	    permute(s,0,s.size()-1);
	    cout<<endl;
	}
	    
    return 0;
}   
