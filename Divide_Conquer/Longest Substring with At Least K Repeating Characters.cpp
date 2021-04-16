/*   https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/submissions/    */

/*
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105
*/

class Solution {
public:
    int fun(string s, int k, int start, int end)
    {
        if (end < k) 
            return 0;
        
        int countMap[26] = {0};
        // update the countMap with the count of each character
        for (int i = start; i < end; i++)
            countMap[s[i] - 'a']++;
        
        for (int mid = start; mid < end; mid++) {
            if (countMap[s[mid] - 'a'] >= k) continue;
            int midNext = mid + 1;
            while (midNext < end && countMap[s[midNext] - 'a'] < k) 
                midNext++;
            return max(fun(s,k, start, mid),
                    fun(s,k, midNext, end));
        }
        return (end - start);
    }
    int longestSubstring(string s, int k) {
        
        int m = 0,mid = -1;
        int n = s.size();
        
        if(n<k )       // No substring possible
            return 0;
        
        return fun(s,k,0,n);
    }
};
