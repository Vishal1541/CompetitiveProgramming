#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

long long int A;
long long int N, K;


void evaluate(long long int arr[], long long int i){
	long long int m_i = A % (long long int)pow(N+1,i+1);
	long long int indexVal;
	if(i==0){
		indexVal = m_i;
		arr[i] = indexVal;
	}
	else{
		long long int m_i_1 = A % (long long int)pow(N+1,i);
		indexVal = (m_i - m_i_1) / pow(N+1,i);
		arr[i] = indexVal;
	}
	A = A - m_i;
	if(A==0)
		return;
	else
		evaluate(arr, i+1);
}

int main(){
	scanf("%lld %lld %lld",&A,&N,&K);
	long long int arr[K];
	for(long long int i=0; i<K; i++)
		arr[i] = 0;
	if(N==0){
		for(long long int i=0; i<K-1; i++)
			printf ("0 ");
		printf ("0\n");
		return 0;
	}
	evaluate(arr, 0);
	for(long long int i=0; i<K-1; i++)
		printf ("%lld ",arr[i]);
	printf ("%lld\n",arr[K-1]);

	return 0;
}