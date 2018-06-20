#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;

int main(){
	scanf("%d",&N);
	int arr1[N];
	vector<bool> visited1(N,0);
	for(int i=0; i<N; i++){
		scanf("%d",&arr1[i]);
	}
	int COST1 = 0;
	for(int i=0; i<N; i++){
		if(i<N-1){
			if(!visited1[i] && !visited1[i+1]){
				if(arr1[i] < arr1[i+1]){
					COST1 += arr1[i];
					visited1[i] = true;
				}
				else{
					COST1 += arr1[i+1];
					visited1[i+1] = true;
				}
			}
		}
		else{
			if(!visited1[i] && !visited1[0]){
				if(arr1[i] < arr1[0]){
					COST1 += arr1[i];
					visited1[i] = true;
				}
				else{
					COST1 += arr1[0];
					visited1[0] = true;
				}
			}
		}
	}

	int arr2[N];
	for(int i=0; i<N ;i++){
		arr2[i] = arr1[N-1-i];
	}
	vector<bool>visited2(N,0);
	int COST2 = 0;

	for(int i=0; i<N; i++){
		if(i<N-1){
			if(!visited2[i] && !visited2[i+1]){
				if(arr2[i] < arr2[i+1]){
					COST2 += arr2[i];
					visited2[i] = true;
				}
				else{
					COST2 += arr2[i+1];
					visited2[i+1] = true;
				}
			}
		}
		else{
			if(!visited2[i] && !visited2[0]){
				if(arr2[i] < arr2[0]){
					COST2 += arr2[i];
					visited2[i] = true;
				}
				else{
					COST2 += arr2[0];
					visited2[0] = true;
				}
			}
		}
	}
	if(COST1<COST2)
		printf("%d\n",COST1);
	else
		printf("%d\n",COST2);

	return 0;
}