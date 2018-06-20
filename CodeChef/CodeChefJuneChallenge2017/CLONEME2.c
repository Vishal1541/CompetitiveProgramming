#include <stdio.h>

int T, N, Q;
int a, b, c, d;

typedef struct s{
	int val;
	int index;
}typeData;

void mergeSort(typeData d[], int l, int u){
	int m = (l+u)/2,i;
	if(l<u){
		mergeSort(d,l,m);
		mergeSort(d,m+1,u);
		merge(d,l,m,u);
	}
}

void merge(typeData d[], int l, int m, int u){
	int p1 = l, p2 = m+1;
	typeData r[u-l+2];
	int i=0,k,x;
	while(!(p1==(m+1) || p2==(u+1) )){
		if(d[p1].val < d[p2].val)	r[i++] = d[p1++];
		else						r[i++] = d[p2++];
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
		typeData Array[N];
		int j;
		for(j=0; j<N; j++){
			scanf("%d",&Array[j].val);
			Array[j].index = j;
		}
		mergeSort(Array, 0, N-1);
		int mismatch = 0;
		for(j=0; j<Q; j++){
			scanf("%d %d %d %d",&a,&b,&c,&d);
			a--;
			b--;
			c--;
			d--;
			int len = b-a+1;
			int A1[N];
			int A2[N];
			int n1[len];
			int n2[len];
			n1[0] = 0;
			n2[0] = 0;
			int k;
			for(k=0; k<N; k++){
				if(k>=a && k<=b)
					A1[k] = 1;
				else
					A1[k] = 0;

				if(k>=c && k<=d)
					A2[k] = 1;
				else
					A2[k] = 0;
			}
			int back = 0, front1 = 0, front2 = 0;
			int val1 = 0, val2 = 0;
			for(k=0; k<N; k++){
				int array_index = Array[k].index;
				val1=n1[back];
				val2=n2[back];
				if(A1[array_index] == 1){
					n1[front1] = Array[k].val;
					front1++;
					if(front1!=len)
						n1[front1] = 0;
					val1 = n1[back];
				}
				if(A2[array_index] == 1){
					n2[front2] = Array[k].val;
					front2++;
					if(front2!=len)
						n2[front2] = 0;
					val2 = n2[back];
				}
				if(val1!=0 && val2!=0){
					if(val1!=val2)
						mismatch++;
					back++;
				}
				if(mismatch>1)
					break;
			}
			if(mismatch>1)
				printf("NO\n");
			else
				printf("YES\n");

			/*printf("\n\n");
			printf("A1 %d %d %d %d %d %d %d\n", A1[0],A1[1],A1[2],A1[3],A1[4],A1[5],A1[6]);
			printf("A2 %d %d %d %d %d %d %d\n", A2[0],A2[1],A2[2],A2[3],A2[4],A2[5],A2[6]);
			printf("n1 %d %d %d\n",n1[0],n1[1],n1[2] );
			printf("n2 %d %d %d\n",n2[0],n2[1],n2[2] );
			printf("mismatch %d\n",mismatch );
			*/
			mismatch = 0;
		}
	}

	return 0;
}