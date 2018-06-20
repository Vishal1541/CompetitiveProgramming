#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isOdd(int i){
	return i%2;
}

int main(){
	int S, N;
	scanf("%d",&S);
	int i;
	for(i=0; i<S; i++){
		scanf("%d",&N);
		int H[N];
		int j, flag=1;
		for(j=0; j<N; j++)
			scanf("%d",&H[j]);
		if(!isOdd(N) || !(H[0]==1 && H[N-1]==1) ){
			flag = 0;
			printf("no\n");
			continue;
		}
		for(j=0; j<=N/2; j++){
			if(H[j]!= j+1){
				flag = 0;
				printf("no\n");
				break;
			}
		}
		if(flag==0)
			continue;
		int Max = N/2 + 1;
		for(j=N/2 + 1; j<N; j++){
			if(H[j]!=Max-1){
				flag = 0;
				printf("no\n");
				break;
			}
			Max--;
		}
		if(flag==0)
			continue;
		printf("yes\n");
	}
	return 0;
}