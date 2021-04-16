/*
https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1/?track=amazon-arrays&batchId=192#
Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.

Example 1:

Input:
N = 4
A[] = {8,3,1,2}
Output: 29
Explanation: Above the configuration
possible by rotating elements are
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11
Here the max sum is 29 
Your Task:
Your task is to complete the function max_sum which takes two arguments which is the array A [ ] and its size and returns an integer value denoting the required max sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

*/
int max_sum(int A[], int n)
    {
 int sum=A[0];
 int max_sum=0;
 for(int i=1;i<n;++i)
{ sum+=A[i];
    max_sum+=(i)*A[i];
}
int res=max_sum;
 for(int i=1;i<n;++i)
 {
     max_sum=max_sum-(sum-A[i-1])+A[i-1]*(n-1);
     res=Math.max(res,max_sum);
 }
 return res;
    } 
