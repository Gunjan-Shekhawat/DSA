string Solution::intToRoman(int A) {
vector<pair<int,string>>v;
v.push_back(make_pair(1000,"M"));
v.push_back(make_pair(900,"CM"));
v.push_back(make_pair(500,"D"));
v.push_back(make_pair(400,"CD"));
v.push_back(make_pair(100,"C"));
v.push_back(make_pair(90,"XC"));
v.push_back(make_pair(50,"L"));
v.push_back(make_pair(40,"XL"));
v.push_back(make_pair(10,"X"));
v.push_back(make_pair(9,"IX"));
v.push_back(make_pair(5,"V"));
v.push_back(make_pair(4,"IV"));
v.push_back(make_pair(1,"I"));

int i{0};
string s;
while(A!=0){
    if(A>=v[i].first){
        int x=A/v[i].first;
        for(int j{1};j<=x;j++)
            s+=v[i].second;
        A=A%v[i].first;
    }
    i++;
}
return s;
}
