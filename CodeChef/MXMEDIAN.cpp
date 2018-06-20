#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		scanf("%d",&N);
		vector <int> arr(2*N,0), arrB(N,0);
		int j;
		for(j=0; j<2*N; j++)
			scanf("%d",&arr[j]);
		sort(arr.begin(), arr.end());
		int index = 0;
		for(j=N; j<2*N; j++){
			arrB[index++] = arr[j];
		}
		printf("%d\n",arrB[int(N/2)]);
		for(j=0; j<N; j++)
			printf("%d %d ",arr[j], arr[j+N]);
		printf("\n");
	}

	return 0;
}