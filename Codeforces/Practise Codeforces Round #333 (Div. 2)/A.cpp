#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
typedef unsigned long long int lli;
using namespace std;

lli n, bx, m, by;

int main(){
	cin>>n>>bx;
	lli input;

	lli sumX = 0;
	lli sumY = 0;
	for(int i=0; i<n; i++){
		cin>>input;
		sumX += input * pow(bx,n-i-1);
	}

	cin>>m>>by;

	for(int i=0; i<m; i++){
		cin>>input;
		sumY += input * pow(by,m-i-1);
	}

	//printf("%llu %llu\n",sumX,sumY );
	if(sumX<sumY)
		printf("<\n");
	else if(sumX>sumY)
		printf(">\n");
	else
		printf("=\n");
	return 0;
}