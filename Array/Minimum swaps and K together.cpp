/*
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Example 1:

Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
Output : 1
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function minSwap() that takes an array (arr), sizeOfArray (n), an integer K, and return the minimum swaps required. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/
                                            /*                      SLIDING WINDOW CONCEPT                 */
int minSwap(int *arr, int n, int k) {
    int maximum_length = 0;
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
            count++;
    }
    
    for(int i=0;i<count;i++)
    {
        if(arr[i]<=k)
            maximum_length++;
    }
    
    //cout<<maximum_length<<endl;
    
    int v = maximum_length;

    for(int i = count;i<n;i++)
    {
        if(arr[i]<=k)
            v++;
        if(arr[i-count]<=k)
            v--;
        maximum_length = max(maximum_length,v);
        //cout<<i<<" "<<maximum_length<<endl;
    }
    //cout<<count<<" "<<maximum_length;
    return count - maximum_length;
}
