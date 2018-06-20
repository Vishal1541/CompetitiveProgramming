#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, N;
long INF = 1000000001;

long difference(long a, long b){
	if(a-b>0)
		return a-b;
	else
		return b-a;
}

int main(){
	scanf("%d",&T);
	int i;
	for(i=0 ;i<T; i++){
		scanf("%d",&N);
		int j;
		long S[N];
		for(j=0; j<N; j++)
			scanf("%ld",&S[j]);
		long min = INF;
		int k,l;
		for(k=0; k<N; k++)
			for(l=k+1; l<N; l++){
				if(difference(S[k],S[l]) < min)
					min = difference(S[k],S[l]);
			}
			printf("%ld\n", min);
	}

	return 0;
}