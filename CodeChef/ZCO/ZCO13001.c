#include <stdio.h>
#include <stdlib.h>

typedef struct s{
	int value;
	int flag;
	struct list *next;
}list;

int N;
unsigned long long int ANS = 0;

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

void mergeSort(int d[], int l, int u){
	int m = (l+u)/2;
	if(l<u){
		mergeSort(d,l,m);
		mergeSort(d,m+1,u);
		merge(d,l,m,u);
	}
}

int main(){
	scanf("%d",&N);
	int arr[N];
	list *back, *front;
	back = malloc(sizeof(list));
	front = back;
	front->next=NULL;
	front->value = 0;
	front->flag = 0;
	int i;
	for(i=0; i<N; i++)
		scanf("%d",&arr[i]);
	mergeSort(arr, 0, N-1);
	front->value = arr[1] - arr[0];
	front->flag = 1;
	ANS += front->value;
	if(N==2){
		printf("%d\n",front->value);
		return 0;
	}
	for(i=2; i<N; i++){
		int diff = arr[i] - arr[i-1];
		front->next = malloc(sizeof(list));
		front = (list*)front->next;
		front->value = diff;
		front->flag = 1;
		front->next = NULL;
		ANS += diff;
		do{
			front->next = malloc(sizeof(list));
			front = (list*)front->next;
			front->value = diff + back->value;
			ANS += diff + back->value;
			front->flag = 0;
			front->next = NULL;
			list *temp = back;
			back = (list*)back->next;
			free(temp);
			/*added_arr[++pointer_front] = diff + added_arr[pointer_back];
			ANS += diff + added_arr[pointer_back];
			pointer_back++;
			*/
		}
		while(back->flag != 1);
	}
	printf("%llu\n",ANS);
	return 0;
}