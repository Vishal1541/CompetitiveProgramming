#include <stdio.h>
#include <string.h>

int T,N=100000;

int getOrder(char a){
	if(a=='C')
		return 1;
	else if(a=='E')
		return 2;
	return 3;
}

int main(){
	scanf("%d",&T);
	int i;
	char s[N+1];
	for (i = 0; i < T; ++i){
		scanf("%s",s);
		int length = strlen(s);
		int j;
		int possible = 1;
		for(j=0; j<length; j++){
			char task = s[j];
			char task_ahead = s[j+1];
			int order = getOrder(task);
			int order_ahead = getOrder(task_ahead);
			if(order_ahead >= order)
				continue;
			else{
				possible = 0;
				break;
			}
		}
		if(possible)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}