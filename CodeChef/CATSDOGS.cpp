#include <iostream>
#include <cstdio>

using namespace std;

int T, C, D, L;

int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		scanf("%d %d %d",&C,&D,&L);
		unsigned long long int MIN, MAX;
		MAX = (C+D)*4;
		if(C-2*D<0){
			MIN = 4*D;
		}
		else
			MIN = (C-D)*4;
		if(L>=MIN && L<=MAX && L%4==0)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}