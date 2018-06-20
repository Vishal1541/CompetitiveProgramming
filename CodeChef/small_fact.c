#include<stdio.h>
int Fact(int n){
    int f=1,i;
    for(i=1;i<=n;i++)
        f*=i;
    return f;
}
int main(){
	int T,N,F,i;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&N);
		F = Fact(N);
		printf("\n%d",F);
	}
	return 0;
}
