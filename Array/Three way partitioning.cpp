/*
Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.


Example 1:

Input: 
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1

You dont need to read input or print anything. The task is to complete the function threeWayPartition() which takes the array[], a and b as input parameters and modifies the array in-place according to the given conditions.
Note: The generated output is 1 if you modify the given array successfully.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

*/

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        
        int low = 0, mid = 0, high = arr.size()-1;
        while(mid<=high)
        {
            if(arr[mid]>b)
            {
                swap(arr[mid],arr[high]);
                high--;
            }
            else if(arr[mid]<a)
            {
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else
                mid++;
                                      
        }
    }
};
