/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different

*/

int Solution::colorful(int A) {
    int n = A;
    unordered_map<int,int>m;
    vector<int>v;
    while(n)
    {
        int c = n%10;
        v.push_back(c);
        n = n/10;
    }
    
    for(int i=0;i<v.size();i++)
    {
        int pr = v[i];
        if(m[pr]!=0)
        {
                return 0;
        }
        m[pr]++;
        for(int j=i+1;j<v.size();j++)
        {  
            pr *= v[j];
            if(m[pr]!=0)
            {
                return 0;
            }
            m[pr]++;
        }
    }
    return 1;
}
