#include <bits/stdc++.h>
using namespace std;
bool isValidPreorder(int pre[], int n) {
   stack<int> stk;
   int root = INT_MIN;
   for (int i=0; i<n; i++) {
      if (pre[i] < root)
         return false;
      while (!stk.empty() && stk.top()<pre[i]) {
         root = stk.top();
         stk.pop();
      }
      stk.push(pre[i]);
   }
   return true;
}
int main() {
   
   int t;
   cin>>t;
   while(t--)
   {
    int n;
   cin>>n;
   int pre[n];
   for(int i=0;i<n;i++)
   cin>>pre[i];
   cout << isValidPreorder(pre, n)<<endl; 
       
   }
       
}
