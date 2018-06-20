#include <iostream>
using namespace std;
 
// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
int smallestSubWithSum(int arr[], int n, int x)
{
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n+1;
 
    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n)
    {
        // Keep adding array elements while current sum
        // is smaller than x
        while (curr_sum <= x && end < n)
        {
            // Ignore subarrays with negative sum if
            // x is positive.
            if (curr_sum <= 0 && x > 0)
            {
                start = end;
                curr_sum = 0;
            }
 
            curr_sum += arr[end++];
        }
 
        // If current sum becomes greater than x.
        while (curr_sum > x && start < n)
        {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;
 
            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}
 
 
/* Driver program to test above function */
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
            
        }
        int res = smallestSubWithSum(arr,n,d-1);
        cout<<(res==n+1?-1:res)<<endl;
    }
 
    return 0;
}
/*
2
5 -4
1 2 3 1 -5
5 4
1 2 3 1 -5
*/