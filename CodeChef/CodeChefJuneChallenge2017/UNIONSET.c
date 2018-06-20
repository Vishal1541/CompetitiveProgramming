#include <stdio.h>

int T, N, K, len;

void init(int arr[N][K]){
	int i,j;
	for(i=0; i<N; i++)
		for(j=0; j<K; j++)
			arr[i][j] = 0;
}

int summation(int a){
	int i=0;
	int j;
	for(j=1; j<=a; j++){
		i = i + j;
	}
}

int main(){
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		scanf("%d %d",&N,&K);
		int arr[N][K];
		init(arr);
		int j,k;
		int count[N];
		for(j=0; j<N; j++)
			count[j] = 0;
		for(j=0; j<N; j++){
			scanf("%d",&len);
			for(k=0; k<len; k++){
				int val;
				scanf("%d",&val);
				val--;
				arr[j][val] = 1;
				count[j]++;
			}
		}
		int COUNT_FINAL = 0, COUNT_FULL=0;
		for(j=0; j<N; j++){
			int temp_count=count[j];
			if(count[j]==K)
				COUNT_FULL++;
			else{
				int l;
				for(l=0; l<N; l++){
					if(count[l]!=K && l!=j && l>j){
						int m;
						for(m=0; m<K; m++){
							if(arr[l][m]==1 && arr[j][m]==0){
								temp_count++;
							}
						}
						if(temp_count==K)
							COUNT_FINAL++;
						temp_count = 0;
					}
				}
			}
		}
		if(COUNT_FULL>0){
			int ADD = 0;
			if(COUNT_FULL>1)
				ADD = summation(COUNT_FULL-1);
			ADD = ADD + (N-COUNT_FULL)*COUNT_FULL;
			COUNT_FINAL = COUNT_FINAL + ADD;
		}
		printf("%d\n",COUNT_FINAL);
	}

	return 0;
}