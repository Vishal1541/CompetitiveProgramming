#include <stdio.h>

int main(){
	int flag=1,inc=1;
	for(int i=1;i<=10;i++){
		printf("%d ",i);
		if(flag==i){
			printf("\n");
			inc++;
			flag+=inc;
		}
	}
	return 0;
}