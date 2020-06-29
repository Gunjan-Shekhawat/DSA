/*
  PROBLEM : You have an empty sequence, and you will be given N queries. Each query is one of these three types:
  1 x  -Push the element x into the stack.
  2    -Delete the element present at the top of the stack.
  3    -Print the maximum element in the stack.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int t;
    cin>>t;
    stack<int>s;
    vector<int>v;
    while(t--)
    {
        int a,b,m=0;
        cin>>a;
        if(a==1)
        {
            cin>>b;
            if(s.empty())
            s.push(b);   
            else
            s.push(max(b,s.top()));             
        }
        else if(a==2)
        {
            s.pop();
        }
        else if(a==3)
        cout<<s.top()<<endl;
    }  

    return 0;
}
