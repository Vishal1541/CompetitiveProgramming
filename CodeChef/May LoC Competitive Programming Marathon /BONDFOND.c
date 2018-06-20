#include <stdio.h>

int T;
long long int N;
long long int power2Array[61] = {0};

long long int power(int a, int b){
	long long int ret = 1;
	int i;
	for(i=0; i<b; i++){
		ret = ret * a;
	}
	return ret;
}

long long int difference(long long a, long long b){
	if(a-b>0)
		return a-b;
	else
		return b-a;
}

int main(){
	scanf("%d",&T);
	int i;
	int exponent = 0;
	for(i=0; i<61; i++){
		power2Array[i] = power(2,i);
	}
	for(i=0; i<T; i++){
		scanf("%lld",&N);
		if(N==1 || N==2){
			printf("0\n");
			continue;
		}
		long long int MIN_DIFFERENCE = N;
		int j=0;
		while(difference(N,power2Array[j]) < MIN_DIFFERENCE){
			MIN_DIFFERENCE = difference(N,power2Array[j]);
			j++;
		}
		printf("%lld\n",MIN_DIFFERENCE);		
	}

	return 0;
}