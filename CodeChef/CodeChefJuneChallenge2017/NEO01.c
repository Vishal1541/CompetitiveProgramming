#include <stdio.h>

int T, N;

void mergeSort(int d[], int l, int u){
	int m = (l+u)/2,i;
	if(l<u){
		mergeSort(d,l,m);
		mergeSort(d,m+1,u);
		merge(d,l,m,u);
	}
}

void merge(int d[], int l, int m, int u){
	int p1 = l, p2 = m+1;
	int r[u-l+2];
	int i=0,k,x;
	while(!(p1==(m+1) || p2==(u+1) )){
		if(d[p1] < d[p2])	r[i++] = d[p1++];
		else				r[i++] = d[p2++];
	}
	if(p1==m+1)
		for(k=p2;k<=u;k++)		r[i++] = d[k];
	else
		for(k=p1;k<=m;k++)		r[i++] = d[k];
	i=0;
	for(x=l;x<=u;x++)			d[x] = r[i++];
}
int main(){
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		scanf("%d",&N);
		int A[N];
		int j;
		for(j=0; j<N; j++)
			scanf("%d",&A[j]);
		mergeSort(A, 0, N-1);
		long long int SUM=0;
		int pointer = N-1;
		int pointer_break = N-1;
		while(1){
			long long int SUBSET_SIZE = 0;
			long long int SUM_TEMP_NON_NEGATIVE = 0;
			long long int SUM_TEMP_NEGATIVE = 0;
			while(A[pointer] >=0 ){
				SUM_TEMP_NON_NEGATIVE += A[pointer];
				SUBSET_SIZE++;
				pointer--;
				if(pointer<0)
					break;
			}
			SUM += SUBSET_SIZE * SUM_TEMP_NON_NEGATIVE;
			if(pointer<0)
				break;
			pointer_break = pointer;
			while(pointer>=0){
				SUM_TEMP_NEGATIVE += A[pointer];
				pointer--;
			}
			SUM += SUM_TEMP_NEGATIVE;
			long long int SUM_TEMP = SUM;
			while(SUM_TEMP>=SUM){
				SUM = SUM_TEMP;
				SUM_TEMP_NON_NEGATIVE += A[pointer_break];
				SUBSET_SIZE++;
				SUM_TEMP_NEGATIVE -= A[pointer_break];
				pointer_break--;
				SUM_TEMP = SUM_TEMP_NEGATIVE + SUBSET_SIZE * (SUM_TEMP_NON_NEGATIVE);
			}
			break;
		}

		printf("%lld\n",SUM);
	}

	return 0;
}