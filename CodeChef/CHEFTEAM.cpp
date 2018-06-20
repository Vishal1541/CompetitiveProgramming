#include <iostream>
#include <cstdio>

unsigned long long int T, N, R;

unsigned long long int nChooseR( unsigned long long int n, unsigned long long int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    unsigned long long int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main(){
	scanf("%llu",&T);
	for(int i=0; i<T; i++){
		scanf("%llu %llu",&N,&R);
		unsigned long long int Ans;
		Ans = nChooseR(N,R);
		printf("%llu\n",Ans);
	}

	return 0;
}