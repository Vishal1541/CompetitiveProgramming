#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
unsigned long long int N;

unsigned long long int nCr( unsigned long long int n, unsigned long long int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    unsigned long long int result = n;
    for( unsigned long long int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main(){
	scanf("%llu",&N);
	vector<int> arr(N);
	for(unsigned long long int i=0; i<N; i++)
		cin>>arr[i];
	sort(arr.begin(),arr.end());
	unsigned long long int MIN = arr[0]*arr[1]*arr[2];
	if(N==3){
		printf("1\n");
		return 0;
	}
	vector<int> ijk(3,0), count(3,0);
	unsigned long long int LIMIT = arr[2];
	ijk[0] = arr[0];
	ijk[1] = arr[1];
	ijk[2] = arr[2];
	unsigned long long int find_count_pointer = 1, count_pointer = 0;
	count[0]++;
	while(arr[find_count_pointer] <= LIMIT){
		if(arr[find_count_pointer] == arr[find_count_pointer-1]){
			count[count_pointer]++;
		}
		else if(arr[find_count_pointer] != arr[find_count_pointer-1]){
			count_pointer++;
			while(ijk[count_pointer]==ijk[count_pointer-1]){
				count[count_pointer] = count[count_pointer-1];
				count_pointer++;
			}
			count[count_pointer]++;			
		}
		find_count_pointer++;
	}
	/*for(unsigned long long inti=0; i<3; i++){
		printf("ijk = %d count = %d \n",ijk[i],count[i] );
	}*/
	unsigned long long int nCr_POINTER = 1;
	unsigned long long int n,r;
	unsigned long long int ANS = 1;
	n = count[0];
	r = 1;
	for(unsigned long long int i=1; i<3; i++){
		if(ijk[i] == ijk[i-1]){
			r++;
		}
		else if(ijk[i] != ijk[i-1]){
			ANS = ANS * nCr(n,r);
			n = count[i];
			r = 1;
		}
	}
	ANS = ANS * nCr(n,r);
	printf("%llu\n", ANS);
	
	return 0;
}