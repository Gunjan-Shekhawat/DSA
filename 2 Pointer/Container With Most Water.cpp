/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i 
is at (i, ai) and (i, 0).
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
*/

class Solution {
public:
    int maxArea(vector<int>& h) {
        int m = 0,n = h.size();
        int l_line=0, r_line=n-1;
        while(l_line<r_line)
        {
            if(h[l_line]>h[r_line])
            {
                m = max(m,h[r_line]*(r_line-l_line));
                r_line--;
            }
            else
            {
                m = max(m,h[l_line]*(r_line-l_line));
                l_line++;
            }
        }
        return m;
    }
};
