#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int T;

int main(){
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		int n,m;
		scanf("%d %d",&n,&m);
		vector<int> arr(n,0);
		int j;
		for(j=0; j<m; j++){
			int mNum;
			scanf("%d",&mNum);
			mNum--;
			arr[mNum] = 1;
		}
		vector<int> indices1(n), indices2(n);
		int pointer1 = -1, pointer2 = -1;
		int count = 2;
		for(j=0; j<n; j++){
			if(arr[j]==0 && count==2){
				indices1[++pointer1]  = j+1;
				count = 1;
				continue;
			}
			if(arr[j]==0 && count==1){
				indices2[++pointer2] = j+1;
				count = 2;
				continue;
			}
		}
		if(pointer1==-1)
			printf("\n");
		else{
			for(j=0; j<=pointer1-1; j++)
			printf("%d ",indices1[j]);
			printf("%d\n", indices1[j]);
		}
		if(pointer2==-1)
			printf("\n");
		else{
			for(j=0; j<=pointer2-1; j++)
			printf("%d ",indices2[j]);
			printf("%d\n", indices2[j]);
		}
	}

	return 0;
}