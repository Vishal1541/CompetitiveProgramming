#include <stdio.h>
int T, K;
int arr[1000001];

int length(int a){
	int divisor = 10;
	int len = 0;
	int MOD = a%divisor;
	len++;
	while(MOD!=a){
		divisor *= 10;
		MOD = a%divisor;
		len++;
	}
	return len;
}

void getIntoArray(int arr[], int K, int len){
	int divisor = 10;
	int mod1 = K%divisor;
	arr[len-1] = mod1;
	int i;
	for(i=len-2; i>=0; i--){
		mod1 = K%divisor;
		divisor *= 10;
		int mod2 = K%divisor;
		arr[i] = (mod2-mod1)*10/divisor;
	}
}

int isPalindrome(int arr[], int len){
	int front=0, back=len-1;
	while(front<=back){
		int a = arr[front];
		int b = arr[back];
		if(a!=b)
			break;
		front++;
		back--;
	}
	if(front>back)
		return 1;
	else 
		return 0;
}

int main(){
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		scanf("%d",&K);
		K++;
		int len = length(K);
		getIntoArray(arr, K,len);
		/*int j;
		for(j=0; j<len; j++)
			printf("..%d..", arr[j]);
		*/
		/*int pali = isPalindrome(arr,len);
		printf("is pali %d\n", pali);
		*/
		while(!isPalindrome(arr,len)){
			K++;
			//printf("K = %d\n", K);
			len = length(K);
			getIntoArray(arr,K,len);
		}
		printf("%d\n",K);
	}

	return 0;
}