#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pointer = -1;
int T, N, Q, K;
int INF = -1;
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

void eatSnake(int stack[N]){
	stack[pointer] = INF;
	pointer--;
	stack[pointer] = stack[pointer] + 1;
	int p_temp = pointer;
	if(p_temp>0)
		while(stack[p_temp] > stack[p_temp-1]){
			int temp = stack[p_temp];
			stack[p_temp] = stack[p_temp-1];
			stack[p_temp-1] = temp;
			p_temp--;
		}
}

void process(int stack[N]){
	while(!(stack[pointer] >= K)){
		if(pointer==0)
			break;
		eatSnake(stack);
	}
	if(pointer > 0)
		printf("%d\n",pointer+1);
	else if(pointer==0 && stack[pointer] > K)
		printf("1\n");
	else
		printf("0\n");
}

int main(){
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		scanf("%d",&N);
		int array[N];
		scanf("%d",&Q);
		int j;
		for(j=0 ;j<N ;j++)
			scanf("%d",&array[j]);
		qsort(array,N,4,cmpfunc);
		int stack[N];
		for(j=0 ;j<N ;j++)
			stack[j] = array[N-j-1];
		pointer = N-1;
		for(j=0 ;j<Q; j++){
			scanf("%d",&K);
			process(stack);
			int k;
			for(k=0 ;k<N ;k++)
				stack[k] = array[N-k-1];
			pointer = N-1;
		}
	}

	return 0;
}