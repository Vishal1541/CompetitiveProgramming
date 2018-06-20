#include<stdio.h>
int main(){
	int T,N,i,rem;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&N);
		rem=N%8;
		switch(rem){
			case 1:	printf("%dLB\n",N+3);break;
			case 2:	printf("%dMB\n",N+3);break;
			case 3:	printf("%dUB\n",N+3);break;
			case 4:	printf("%dLB\n",N-3);break;
			case 5:	printf("%dMB\n",N-3);break;
			case 6:	printf("%dUB\n",N-3);break;
			case 7:	printf("%dSU\n",N+1);break;
			case 0:	printf("%dSL\n",N-1);break;
		}
	}
	
	return 0;
}