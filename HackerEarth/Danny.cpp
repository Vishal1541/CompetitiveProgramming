#include <iostream>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int N, K;

int difference(int a, int b){
	if(a-b>0)
		return a-b;
	else
		return b-a;
}

int main(){
	scanf("%d %d",&N,&K);
	vector<int> ms((N*(N-1))/2);
	int arr[N];
	for(int i=0; i<N; i++){
		scanf("%d",&arr[i]);
	}
	int count=0;
	for(int i=1; i<N; i++){
		for(int j=0; j<i; j++){
			int diff = difference(arr[i], arr[j]);
			ms[count] = diff;
			count++;
		}
	}
	sort(ms.begin(),ms.end());
	printf("%d\n",ms[K-1]);

	return 0;
}