#include <stdio.h>

int T, n;

int main(){
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		scanf("%d",&n);
		if(n==1)
			printf("1\n");
		else{
			printf("1");
			int j;
			int odd = 3;
			for(j=1; j<n; j++){
				printf(" %d",odd);
				odd = odd + 2;
			}
			printf("\n");
		}
	}

	return 0;
}