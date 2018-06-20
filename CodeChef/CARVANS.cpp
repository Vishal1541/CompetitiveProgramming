#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

int T, N;

int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		scanf("%d",&N);
		int cars[N];
		for(int j=0; j<N; j++){
			scanf("%d",&cars[j]);
		}
		int MIN = cars[0], COUNT = 1;
		for(int j=1; j<N; j++){
			if(cars[j] <= MIN){
				MIN = cars[j];
				COUNT++;
			}
		}
		printf("%d\n",COUNT);
	}

	return 0;
}