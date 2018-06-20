#include <stdio.h>
#include <stdlib.h>

int T, N, Q, a, b, c, d;

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

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
		scanf("%d %d",&N,&Q);
		int A[N], A1[N], A2[N];
		int j;
		for(j=0; j<N; j++){
			scanf("%d",&A[j]);
			A1[j] = A[j];
			A2[j] = A[j];
		}
		for(j=0; j<Q; j++){
			scanf("%d %d %d %d",&a,&b,&c,&d);
			a--;
			b--;
			c--;
			d--;
			int len = b-a+1;
			//int arr1[len], arr2[len];
			int e;
			/*for(e=a; e<=b; e++)
				arr1[e-a] = A[e];
			for(e=c; e<=d; e++)
				arr2[e-c] = A[e];
			*/
			mergeSort(A1, a, b);
			mergeSort(A2, c, d);

			//qsort(arr1,len,4,cmpfunc);
			//qsort(arr2,len,4,cmpfunc);

			int noMismatch = 0;
			if(a>c){
				for(e=c; e<=d; e++){
					//if(arr1[e] != arr2[e])
					if(A1[e+a-c] != A2[e])
						noMismatch++;
					if(noMismatch>1)
						break;
				}
				if(noMismatch <= 1)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else{
				for(e=a; e<=b; e++){
					//if(arr1[e] != arr2[e])
					if(A1[e] != A2[e+c-a])
						noMismatch++;
					if(noMismatch>1)
						break;
				}
				if(noMismatch <= 1)
					printf("YES\n");
				else
					printf("NO\n");
				
			}
			for(e=0; e<N; e++){
				A1[e] = A[e];
				A2[e] = A[e];
			}
		}
	}

	return 0;
}

