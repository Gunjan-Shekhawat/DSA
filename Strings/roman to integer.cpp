int main() {
	int t; cin>>t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    map<char, int> m;
	    m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int i=0,n=s.size();
        int sum = 0;
        for(i=1;i<n;i++)
        {
            if(m[s[i]]>m[s[i-1]])
            sum-=m[s[i-1]];
            else
            sum+=m[s[i-1]];
        }
        sum+=m[s[i-1]];
        cout<<sum<<endl;
	}
	return 0;
}
