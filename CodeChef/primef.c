#include <stdio.h>

void findPrimeFactors(int number,int divisor){
	if(number==1)	return;
	if(number%divisor==0){
		printf("%d ",divisor);
		number = number/divisor;
	}
	else{
		divisor = divisor+1;
	}
	findPrimeFactors(number,divisor);
}

int main(){
	int n;
	scanf("%d",&n);
	findPrimeFactors(n,2);
	return 0;
}