#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int max_index;
long *max, *left, *right;
int operations;

int findMaxIndex(long h[n]){
	int i, max_index;
	long max=0;
	for(i=0; i<n; i++){
		if(h[i] >  max){
			max = h[i];
			max_index = i;
		}
	}
	return max_index;
}

long mod(long a){
	if(a>0)
		return a;
	else
		return -a;
}

int main(){
	int T;
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		scanf("%d",&n);
		long h[n];
		int j;
		for(j=0; j<n; j++){
			scanf("%ld",&h[j]);
		}
		operations = 0;
		max_index = findMaxIndex(h);
		max = &h[max_index];
		//printf("%ld   %d\n",*max, max_index );
		left = &h[max_index-1];
		right = &h[max_index+1];
		if(*right == *max){
			h[max_index+1]--;
			operations++;
		}
		while(!(*max-*left == 1 && *max-*right==1)){
			h[max_index]--;
			operations++;
			if(*right == *max){
				h[max_index+1]--;
				operations++;
			}
			if(*left == *max){
				h[max_index-1]--;
				operations++;
			}
		}

		int right_increment=2, left_increment=2;
		long temp_max = *max-1;

		
		
		int k;
		for(k=0; k<n; k++)
			printf("%ld  ", h[k]);
		printf("\n%d\n",operations );
	}
	return 0;
}