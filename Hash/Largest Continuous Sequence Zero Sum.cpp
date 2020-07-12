/*
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}
*/

vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int,int> m;
    vector<int> ans;
    int sum=0;
    int max=INT_MIN;
    int begin;
    int end;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
        if(sum==0)
        {
            if(i+1>max)
            {
                max=i+1;
                begin=0;
                end=i;
            }
        }
        else if(m.find(sum)!=m.end())
        {
            if(i-m[sum]>max)
            {
                max=i-m[sum];
                begin=m[sum]+1;
                end=i;
            }
        }
        else
        {
            m[sum]=i;
        }
    }
    if(max==INT_MIN)
        return ans;
    else
    {
        for(int i=begin;i<=end;i++)
        {
            ans.push_back(A[i]);
        }
        return ans;
    }
}
