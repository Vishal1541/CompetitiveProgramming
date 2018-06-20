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
		long difference=0;
		
		//--------------------------RIGHT

		while((max_index+right_increment)!=n){
			while((max_index+right_increment)!=n){
				right = &h[max_index+right_increment];
				if(*right == temp_max){
					h[max_index+right_increment]--;
					operations++;
					right_increment++;
				}
				else if(temp_max - *right == 1){
					temp_max = *right;
					right_increment++;
				}
				else{
					difference = temp_max - *right;
					difference--;
					break;
				}
			}
			if(difference>0){
				int x;
				for(x=max_index-1; x<max_index+right_increment; x++){
					h[x] = h[x] - difference;
					operations = operations + difference;
				}
				temp_max = temp_max - difference;
				difference = 0;
			}
		}


		//--------------------------LEFT

		temp_max = *max-1;
		difference = 0;

		while((max_index-left_increment)!=-1){
			while((max_index-left_increment)!=-1){
				left = &h[max_index-left_increment];
				if(*left == temp_max){
					h[max_index-left_increment]--;
					operations++;
				}
				else if(temp_max - *left == 1){
					temp_max = *left;
					left_increment++;
				}
				else{
					difference = temp_max - *left;
					difference--;
					break;
				}
			}
			if(difference>0){
				int x;
				for(x=max_index-left_increment; x<max_index+right_increment; x++){
					if(h[x] > difference){
						h[x] = h[x] - difference;
						operations = operations + difference;
					}
					else{
						h[x] = 0;
						operations = operations + h[x];
					}
				}
				temp_max = temp_max - difference;
				difference = 0;
			}
			
			else if(difference<0){
				difference = mod(difference);
				h[max_index-left_increment] -= difference;
				operations = operations + difference;
				difference = 0;
			}
			if(h[max_index-left_increment==0] && max_index-left_increment>0){
				int x;
				for(x=max_index-left_increment; x>=0; x--){
					operations = operations + h[x];
					h[x] = 0;
				}
				left_increment = max_index + 1;
			}
		}
		int k;
		for(k=0; k<n; k++)
			printf("%ld  ", h[k]);
		printf("\n%d\n",operations );
	}
	return 0;
}