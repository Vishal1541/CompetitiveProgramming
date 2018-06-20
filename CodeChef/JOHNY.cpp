#include <iostream>
#include <cstdio>
using namespace std;
int T,K,N;
typedef struct s{
	int key;
	int length;
}typeSong;
void merge(typeSong d[], int l, int m, int u){
	int p1 = l, p2 = m+1;
	typeSong r[u-l+2];
	int i=0,k,x;
	while(!(p1==(m+1) || p2==(u+1) )){
		if(d[p1].length < d[p2].length)	r[i++] = d[p1++];
		else				r[i++] = d[p2++];
	}
	if(p1==m+1)
		for(k=p2;k<=u;k++)		r[i++] = d[k];
	else
		for(k=p1;k<=m;k++)		r[i++] = d[k];
	i=0;
	for(x=l;x<=u;x++)			d[x] = r[i++];
}

void mergeSort(typeSong d[], int l, int u){
	int m = (l+u)/2,i;
	if(l<u){
		mergeSort(d,l,m);
		mergeSort(d,m+1,u);
		merge(d,l,m,u);
	}
}


int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		scanf("%d",&N);
		typeSong song[N];
		for(int i=0; i<N; i++){
			scanf("%d",&song[i].length);
			song[i].key = i;
		}
		scanf("%d",&K);
		K--;
		mergeSort(song, 0, N-1);
		int index = 0;
		while(song[index].key != K){
			index++;
		}
		printf("%d\n",index+1);
	}

	return 0;
}