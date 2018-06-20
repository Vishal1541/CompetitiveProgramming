#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int T;
	scanf("%d",&T);
	int i;
	long long n, change1, change2, change3;
	while(scanf("%lld",&n)!=EOF){
		change1 = (long long)n/2;
		change2 = (long long)n/3;
		change3 = (long long)n/4;
		if(change1 + change2 + change3 > n)
			printf("%lld\n",change1 + change2 + change3 );
		else
			printf("%lld\n", n);
	}

	return 0;
}