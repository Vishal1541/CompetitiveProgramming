#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

//I/Q=1 (Head) I/Q=2(Tail)
int T, G, I, N, Q;


int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		scanf("%d",&G);
		for(int j=0; j<G; j++){
			scanf("%d%d%d",&I,&N,&Q);
			if(N%2 == 0){
				printf("%d\n",N/2);
			}
			else{
				if(I==Q)
					printf("%d\n",N/2);
				else
					printf("%d\n",N/2 + 1);
			}
		}

	}

	return 0;
}