#include <stdio.h>

int Max(int a,int b){
	if(a>b)	return a;
	return b;
}

int main(){
	int a,b,c;
	int rank1=0,rank2=0,rank3=0;
	scanf("%d%d%d",&a,&b,&c);

	int M=a;
	if(b>M)	M=b;
	if(c>M)	M=c;

	if(M==a)	rank1=1;
	else if(M==b)	rank2=1;
	else if(M==c)	rank3=1;

	if(rank1==1){
		if(b>c){
			rank2=2;
			rank3=3;
		}
		else{
			rank2=3;
			rank3=2;
		}
	}
	else if(rank2==1){
		if(a>c){
			rank1=2;
			rank3=3;
		}
		else{
			rank1=3;
			rank3=2;
		}
	}
	else{
		if(a>b){
			rank1=2;
			rank2=3;
		}
		else{
			rank1=3;
			rank2=2;
		}
	}
	if(rank1==1)	printf("%d ",a);
	else if(rank2==1)	printf("%d ",b);
	else if(rank3==1)	printf("%d ",c);

	if(rank1==2)	printf("%d ",a);
	else if(rank2==2)	printf("%d ",b);
	else if(rank3==2)	printf("%d ",c);

	if(rank1==3)	printf("%d ",a);
	else if(rank2==3)	printf("%d ",b);
	else if(rank3==3)	printf("%d ",c);



	return 0;
}