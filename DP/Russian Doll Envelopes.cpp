/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

*/
// similar to LIS ( sort the width and apply LIS in the height)
bool comp (vector<int>&a , vector<int>&b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        else
            return a[1]>b[1];
    }
class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        int mx = 0;
        sort(envelopes.begin(),envelopes.end(),comp);
        if(n==0)
            return 0;
        int dp[n];
        for(int i=n-1;i>=0;i--)
        {
            dp[i] = 0;
            for(int j=i+1;j<n;j++)
            {
                if(dp[j] > dp[i] && envelopes[j][1]>envelopes[i][1] && envelopes[j][0]>envelopes[i][0])
                {
                    dp[i] = dp[j];
                }
            }
            dp[i]++;
            mx = max(mx,dp[i]);
        }
        return mx;
    }
};
