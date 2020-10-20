#include <bits/stdc++.h>
using namespace std;
string minWindow(string S, string T) {
    string result;
    if(S.empty() || T.empty()){
        return "-1";
    }
    unordered_map<char, int> map;
    unordered_map<char, int> window;
    for(int i = 0; i < T.length(); i++){
        map[T[i]]++;
    }
    int minLength = INT_MAX;
    int letterCounter = 0;
    int slow = 0;
    for(int fast = 0; fast < S.length(); fast++){
        char c = S[fast];
        if(map.find(c) != map.end()){
            window[c]++;
            if(window[c] <= map[c]){
                letterCounter++;
            }
        }
        if(letterCounter >= T.length()){
            while(map.find(S[slow]) == map.end() || window[S[slow]] > map[S[slow]]){
                window[S[slow]]--;
                slow++;
            }
            if(fast - slow + 1 < minLength){
                minLength = fast - slow + 1;
                result = S.substr(slow, minLength);
            }
        }
    }
    if(result.size()==0)
    return "-1";
    return result;
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    string s,r;
	    cin>>s;
	    cin>>r;
	    cout<< minWindow(s,r)<<endl;
	}
	
	return 0;
}
