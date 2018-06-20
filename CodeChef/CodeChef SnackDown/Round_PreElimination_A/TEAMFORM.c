#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		int n,m;
		scanf("%d",&n);
		scanf("%d",&m);
		int j;
		for(j=0; j<m; j++){
			int u,v;
			scanf("%d",&u);
			scanf("%d",&v);
		}
		if(n%2==0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}