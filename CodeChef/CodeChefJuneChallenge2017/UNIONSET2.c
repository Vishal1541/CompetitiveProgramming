#include <stdio.h>

int T, N, K, len;

void makeAllFlagZero(int flag[N][K]){
	int i,j;
	for(i=0; i<N; i++)
		for(j=0; j<K; j++)
			flag[i][j] = 0;
}

int main(){
	scanf("%d",&T);
	int t;
	for(t=0; t<T; t++){
		scanf("%d %d",&N,&K);
		int arr[N][K], lengthArr[N], flag[N][K];
		makeAllFlagZero(flag);
		int n=0,l=0,k=0;
		int COUNT_FINAL = 0;
		for(n=0; n<N; n++){
			scanf("%d",&len);
			lengthArr[n] = len;
			for(l=0; l<len; l++){
				int val;
				scanf("%d",&val);
				val--;
				arr[n][l] = val;
				flag[n][val] = 1;
			}
		}
		for(n=0; n<N-1; n++){
			int n2;
			int count_left = K - lengthArr[n];
			for(n2=n+1; n2<N; n2++){
				if(count_left==0){
					COUNT_FINAL += N-n-1;
					break;
				}
				else{
					int count_temp = 0;
					for(l=0; l<lengthArr[n2]; l++){
						if(flag[n2][arr[n2][l]]==1 && flag[n][arr[n2][l]]==0){
							count_temp++;
							if(count_temp == count_left)
								break;
						}
					}
					if(count_temp == count_left){
						COUNT_FINAL++;
					}
				}
			}
		}
		printf("%d\n",COUNT_FINAL);
	}
	return 0;
}