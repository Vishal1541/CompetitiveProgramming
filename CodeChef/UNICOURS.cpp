#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int T, N;

int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		scanf("%d",&N);
		vector<int> arr(N,0), flag(N,0);
		for(int i=0; i<N; i++)
			cin>>arr[i];
		int marked = 0;
		for(int i=N-1; i>=0; i--){
			int num = arr[i];
			if(flag[i] == 1)
				break;
			if(num <= marked)
				continue;
			for(int j=marked; j<num; j++){
				flag[j] = 1;
				marked++;
			}
		}
		printf("%d\n",N-marked);
	}

	return 0;
}