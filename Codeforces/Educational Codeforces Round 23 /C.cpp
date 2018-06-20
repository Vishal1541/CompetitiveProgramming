#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long int n, s;

unsigned long long int digitSum(unsigned long long int a){
	unsigned long long int sum = 0;
	unsigned long long int divisor = 10;
	int mod_prv = a % divisor;
	sum += mod_prv;
	divisor *= 10;
	while(1){
		int mod = a%divisor;
		if(mod == mod_prv)
			break;
		sum += (unsigned long long int)((mod - mod_prv)*10)/(unsigned long long int)divisor;
		divisor *= 10;
		mod_prv = mod;
	}
	return sum;
}

int main(){
	scanf("%llu %llu",&n,&s);
	unsigned long long int ANS = 0;
	while(n-digitSum(n)>=s){
		ANS++;
		n--;
	}
	printf("%llu\n", ANS);

	return 0;
}