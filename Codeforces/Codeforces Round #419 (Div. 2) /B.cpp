#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr(200001,0);
int n,k,q;

int isOdd(int a){
	return a%2;
}

int main(){
	scanf("%d %d %d",&n,&k,&q);
	for(int i=0; i<n; i++){
		int t1, t2;
		scanf("%d %d",&t1,&t2);
		int x=0;
		if(isOdd(t2-t1)){
			for(int j=t1; j<=(int)((t2+t1)/2); j++){
				arr[j]++;
				arr[t2-x]++;
				x++;
			}
		}
		else{
			int j;
			for(j=t1; j<(int)((t2+t1)/2); j++){
				arr[j]++;
				arr[t2-x]++;
				x++;
			}
			arr[j]++;
		}
	}
	for(int i=0; i<q; i++){
		int count = 0;
		int t1, t2;
		scanf("%d %d",&t1,&t2);
		int x=0;
		if(isOdd(t2-t1)){
			for(int j=t1; j<=(int)((t2+t1)/2); j++){
				if(arr[j] >= k){
					count++;
				}
				if(arr[t2-x] >= k){
					count++;
				}
				x++;
			}
		}
		else{
			int j;
			for(j=t1; j<(int)((t2+t1)/2); j++){
				if(arr[j] >= k){
					count++;
				}
				if(arr[t2-x] >= k){
					count++;
				}
				x++;
			}
			if(arr[j] >= k)
				count++;
		}
		printf("%d\n",count);
	}

	return 0;
}