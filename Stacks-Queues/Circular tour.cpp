/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).
*/
int tour(petrolPump arr[],int n)
{
    int start = 0;  
    int end = 1;  
    int curr_petrol = arr[start].petrol - arr[start].distance;  

    while (end != start || curr_petrol < 0)  
    {  

        while (curr_petrol < 0 && start != end)  
        {  
            curr_petrol -= arr[start].petrol - arr[start]c.distance;  
            start = (start + 1) % n;  
            if (start == 0)  
            return -1;  
        }  
        curr_petrol += arr[end].petrol - arr[end].distance;  
  
        end = (end + 1) % n;  
    }
    return start;  
} 
