#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n = s.size(),i=0;
	    int st  = 0;
	    int len = 1;
	    while(i<n)
	    {
	        int j = i-1;
	        int k = i+1;
	        int c = 1;
	        while(j>=0 && k<n && s[j]==s[k])
	        {
	            j--;
	            k++;
	            c+=2;
	        }
	        if(c>len)
	        {
	            len = c;
	            st  = j+1;
	        }
	        if(i<n-1 && s[i]==s[i+1])
	        {
	            j = i-1;
	            k = i+2;
	            c = 2;
	            while(j>=0 && k<n && s[j]==s[k])
    	        {
    	            j--;
    	            k++;
    	            c+=2;
    	        }
    	        if(c>len)
    	        {
    	            len = c;
    	            st  = j+1;
    	        }
	        }
	        i++;
	    }
	    //cout<<st <<" "<< len<<endl;
	    string t = s.substr(st, len);
	    cout<<t<<endl;
	}
	return 0;
}
