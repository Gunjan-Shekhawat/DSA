/*

PROBLEM : Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, 
          compute how much water it is able to trap after raining.
          
          Problem Constraints
          1 <= |A| <= 100000
          

          Input Format
          The only argument given is integer array A.



          Output Format
          Return the total water it is able to trap after raining.



          Example Input
          Input 1:

           A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
          Input 2:

           A = [1, 2]
           
           https://www.interviewbit.com/problems/rain-water-trapped/

*/

int Solution::trap(const vector<int> &A) {
int result = 0;
int n = A.size();
int i=0, j=n-1;
int maxLeft = A[i], maxRight = A[j];

if(n<3)
    return 0;

while(i<j)    
{
    if(A[i]<A[j])
    {
        maxLeft = max(maxLeft, A[++i]);
        result += maxLeft - A[i];
    }
    else
    {
        maxRight = max(maxRight, A[--j]);
        result += maxRight - A[j]; 
    }
}
return result;
}


