#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        vector<char> ch(n);
        
        for(int i=0;i<n;i++){
            cin>>ch[i];
        }
        
        int freq[26];
        
        for(int i=0;i<26;i++){
            
            freq[i]=0;
        }
        
        queue<char> q;
        
        for(int i=0;i<n;i++){
            
            freq[ch[i]-'a']++;
            
            q.push(ch[i]);
            
            while(!q.empty()){
                if(freq[q.front()-'a']>1){
                    q.pop();
                }
                else{
                    cout<<q.front()<<" ";
                    break;
                }
                
            }
            if(q.empty()){
                cout<<-1<<" ";
            }
            
        }
        cout<<endl;
    }
	
}
