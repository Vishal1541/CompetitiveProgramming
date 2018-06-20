//    VISHAL ANAND
#include <bits/stdc++.h>

using namespace std;
/*
sort(first_iterator, last_iterator) – To sort the given vector.
reverse(first_iterator, last_iterator) – To reverse a vector.
*max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
*min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements 

count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
find(first_iterator, last_iterator, x) – Points to last address of vector ((name_of_vector).end()) if element is not present in vector.

binary_search(first_iterator, last_iterator, x) – Tests whether x exists in sorted vector or not. use with if()
lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.
upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’. 

arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly.
arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line. 
distance(first_iterator,desired_position) – It returns the distance of desired position from the first iterator.This function is very useful while finding the index. 

n = n << 1;   // Multiply n with 2
n = n >> 1;   // Divide n by 2

Number of digits in N =floor(log10(N)) + 1;

are all of the elements positive?
all_of(first, first+n, ispositive()); 

is there at least one positive element?
any_of(first, first+n, ispositive());

are none of the elements positive?
none_of(first, first+n, ispositive()); 

copy 5 elements from source to target
copy_n(source, 5, target);
*/

int N,L;
int Arr[1000001];


// A utility function to get minimum of two numbers
int minVal(int x, int y) { return (x < y)? x: y; }
int maxVal(int x, int y) { return (x > y)? x: y; }
 
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the minimum value in a given range
     of array indexes. The following are parameters for this function.
 
    st    --> Pointer to segment tree
    index --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                  by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int RMQUtilMin(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return
    //  the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(RMQUtilMin(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtilMin(st, mid+1, se, qs, qe, 2*index+2));
}
 
// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQMin(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return RMQUtilMin(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtilMin(int arr[], int ss, int se, int *st, int si )
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtilMin(arr, ss, mid, st, si*2+1),
                     constructSTUtilMin(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructSTMin(int arr[], int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n))); 
 
    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
 
    int *st = new int[max_size]; 
 
    // Fill the allocated memory st
    constructSTUtilMin(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

//-------------------------------MAX------------------------------------------------
 
int RMQUtilMax(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part of given range, then return
    //  the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return -1;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return maxVal(RMQUtilMax(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtilMax(st, mid+1, se, qs, qe, 2*index+2));
}
 
// Return minimum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses RMQUtil()
int RMQMax(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return RMQUtilMax(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtilMax(int arr[], int ss, int se, int *st, int si )
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] =  maxVal(constructSTUtilMax(arr, ss, mid, st, si*2+1),
                     constructSTUtilMax(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructSTMax(int arr[], int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n))); 
 
    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
 
    int *st = new int[max_size]; 
 
    // Fill the allocated memory st
    constructSTUtilMax(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}



// Driver program to test above functions
int main()
{
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>Arr[i];
    }
 
    // Build segment tree from given array
    int *stMin = constructSTMin(Arr, N);
    int *stMax = constructSTMax(Arr, N);
 
    /*int qs = 1;  // Starting index of query range
    int qe = 5;  // Ending index of query range
 
    // Print minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",
                           qs, qe, RMQMin(stMin, N, qs, qe));
    printf("Maxmimum of values in range [%d, %d] is = %d\n",
                           qs, qe, RMQMax(stMax, N, qs, qe));
    */
    int i,j,k,l;
    unsigned long long int Ans = 0, MOD = 1e9+7;
    for(i=0; i<N; i++){
        for(j=i; j<N; j++){
            for(k=j+1; k<N; k++){
                for(l=k; l<N; l++){
                    Ans = Ans%MOD + ((RMQMax(stMax, N, i, j))%MOD * (RMQMin(stMin, N, k, l))%MOD)%MOD;
                    //cout<<Arr[i]<<Arr[j]<<Arr[k]<<Arr[l]<<" "<<RMQMax(stMax, N, i, j)<<" "<< RMQMin(stMin, N, k, l)<<endl;
                }
            }
        }
    }
    cout<<Ans<<endl;

    return 0;
}