#include <stdio.h>
#include <stdlib.h>

int N, Q, L, R, X, Y;

typedef struct s{
	int number;
	int count;
	struct PrimeNumbers *next;
}PrimeNumbers;

void insert(int value, PrimeNumbers *top){
	PrimeNumbers *node = (PrimeNumbers*) top;
	node->number = value;
	node->count = -1;
	node->next = NULL;
}

void findPrimeFactors(PrimeNumbers *top){
	PrimeNumbers *node = (PrimeNumbers*)top;
	int INIT_NUM = node->number;
	int INIT_STATIC_NUM = node->number;
	int i;
	if(i==1)
		return;
	for(i=2; i<=INIT_STATIC_NUM; i++){
		if(INIT_NUM%i == 0){
			node->next = malloc(sizeof(PrimeNumbers));
			node = (PrimeNumbers*)node->next;
			node->number = i;
			node->count = 0;
			node->next = NULL;
			while(INIT_NUM%i == 0){
				(node->count)++;
				INIT_NUM = INIT_NUM/i;
			}
		}
		if(INIT_NUM==1)
			break;
	}
	return;
}

void findExponents(PrimeNumbers *top, int X, int Y, int *ans){
	PrimeNumbers *node = (PrimeNumbers*)top;
	node = (PrimeNumbers*)node->next;
	int i=X;
	while(1){
		if(node->number == i){
			*ans = *ans + node->count;
			node = (PrimeNumbers*)node->next;
			i++;
		}
		else if(node->number < i){
			node = (PrimeNumbers*)node->next;
		}
		else if(node->number > i){
			i++;
		}
		if(i>Y || node==NULL)
			break;
	}
}
 
int isEmpty(PrimeNumbers *top){
	if(top->next==NULL)
		return 1;
	return 0;
}

int main(){
	scanf("%d",&N);
	PrimeNumbers *numbers[N];
	int i;
	/*for(i=0; i<N; i++){
		numbers[i] = (PrimeNumbers*)malloc(sizeof(PrimeNumbers));
	}
	*/
	for(i=0; i<N; i++){
		int num;
		scanf("%d",&num);
		numbers[i] = (PrimeNumbers*)malloc(sizeof(PrimeNumbers));
		insert(num, numbers[i]);
		//findPrimeFactors(numbers[i]);
	}
	/*for(i=0; i<N; i++){
		PrimeNumbers *a = numbers[i];
		a = (PrimeNumbers*) a->next;
		printf("num %d exp %d\n",a->number, a->count );
	}
	*/
	scanf("%d",&Q);
	for(i=0; i<Q; i++){
		scanf("%d %d %d %d",&L,&R,&X,&Y);
		L--;
		R--;
		int ANSWER = 0;
		int j;
		for(j=L; j<=R; j++){
			if(isEmpty(numbers[j])){
				findPrimeFactors(numbers[j]);
			}				
			findExponents(numbers[j], X, Y, &ANSWER);
		}
		printf("%d\n",ANSWER);
	}


	return 0;
}