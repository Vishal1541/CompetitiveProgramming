#include <stdio.h>
#include <string.h>

int T, e, m ,h;

int isType1(){
	if(e>=1 && m>=1 && h>=1){
		update();
		return 1;
	}
	return 0;	
}

int isType2(){
	if(e>=1 && m>=2){
		update();
		return 1;
	}
	else
		return 0;
}

int isType3(){
	if(e>=2 && m>=1){
		update();
		return 1;
	}
	else
		return 0;
}

void update(){
	e--;
	m--;
	h--;
}

int main(){
	scanf("%d",&T);
	int i, contests;
	for(i=0; i<T; i++){
		contests=0;
		scanf("%d%d%d",&e,&m,&h);
			while(1){
			int a = isType1();
			int b = isType2();
			int c = isType3();
			if(a)
				contests++;
			if(b)
				contests++;
			if(c)
				contests++;
			if(a==b==c==0){
				printf("%d\n",contests);
				break;
			}
		}
	}
	return 0;
}