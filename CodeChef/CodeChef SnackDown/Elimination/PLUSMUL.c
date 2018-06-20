#include <stdio.h>
#define MODULO 1000000007

int T, n;
unsigned long long int sum;
int arrNum[100000];

void makeAllVisitedZero(int visited[], int k){
    int i;
    for(i=0; i<k; i++)
        visited[i] = 0;
}
void makeAllMulOne(int mult[], int k){
    int i;
    for(i=0; i<k; i++)
        mult[i] = 1;
}


void combinationUtil(int arr[], int data[], int start, int end, 
                     int index, int r);
 
// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n0, int r)
{
    // A temporary array to store all combination one by one
    int data[r];
 
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n0-1, 0, r);
}
 
/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r)
{
    // Current combination is ready to be printed, print it
    if (index == r){
        int visited[n];
        makeAllVisitedZero(visited,n);
        int mult[n-1];
        int multPointer=-1;
        makeAllMulOne(mult,n-1);
        int j;
        for (j=0; j<r; j++){
            //printf("%d ", data[j]);
            if( (data[j]+1) != data[j+1] ){
                mult[++multPointer] = arrNum[data[j]-1]*arrNum[data[j]];
                visited[data[j]-1] = 1;
                visited[data[j]] = 1;
            }
            else if( (data[j]+1) == data[j+1] ){
                mult[++multPointer] = arrNum[data[j]-1]*arrNum[data[j]];
                visited[data[j]-1] = 1;
                visited[data[j]] = 1;
                while( (data[j]+1) == data[j+1] && j<r){
                    j++;
                    mult[multPointer] *= arrNum[data[j]];
                    visited[data[j]] = 1;
                }
            }
        }
        //printf("\n");
        for(j=0; j<=multPointer; j++)
            sum = sum + mult[j];
        for(j=0; j<n; j++){
            if(!visited[j]){
                sum = sum + arrNum[j];
            }
        }
        sum = sum % MODULO;
        return;
    }
 
    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    int i;
    for (i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
 
// Driver program to test above functions

int main(){
    scanf("%d",&T);
    int i;
    for(i=0; i<T; i++){
        sum = 0;
        scanf("%d",&n);
        int j;
        for(j=0; j<n; j++)
            scanf("%d",&arrNum[j]);
        int r;
        int N=0;
        int arrIndexSign[n-1];
        for(j=0; j<n-1; j++){
            arrIndexSign[j] = ++N;
        }
        for(j=0; j<n; j++)
            sum += arrNum[j];
        for(j=1; j<=N; j++){
            r = j;
            printCombination(arrIndexSign, N, r);
        }
        printf("%llu\n",sum);
    }
    /*int arr[] = {1, 2, 3, 4, 5};
    int r = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
    */
    return 0;
}