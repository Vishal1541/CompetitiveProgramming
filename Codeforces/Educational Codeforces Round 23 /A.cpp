#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long int x1, y1, x2, y2, x, y;

long long int difference(long long int a, long long int b){
	if(a-b>0)
		return a-b;
	return b-a;
}

int isOdd(long long int a){
	if(a==0)
		return 0;
	return (a%2);
}

int main(){
	scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
	scanf("%lld %lld",&x,&y);

	long long int delta_x, delta_y;
	double x_multiplier, y_multiplier;
	delta_x = difference(x1, x2);
	delta_y = difference(y1, y2);
	x_multiplier = (double)delta_x/(double)x;
	y_multiplier = (double)delta_y/(double)y;
	if((long long int)x_multiplier == (double)x_multiplier && (long long int)y_multiplier == (double)y_multiplier){
		if(isOdd(x_multiplier)&&isOdd(y_multiplier))
			printf("YES\n");
		else if(!isOdd(x_multiplier)&&!isOdd(y_multiplier))
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
		printf("NO\n");
	return 0;
}