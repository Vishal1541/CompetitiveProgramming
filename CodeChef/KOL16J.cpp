#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>
typedef unsigned long long int llu;

using namespace std;

int T, N;

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		vector<int> arr(500,0), A(N), B(N);
		for(int i=0; i<N; i++){
			int input;
			cin>>input;
			input--;
			A[i] = B[i] = input;
			arr[input] = 1;
		}
		sort(B.begin(),B.end());
		bool MISMATCH = false, WRONG = false;
		for(int i=0; i<N; i++){
			if(arr[i]==0){
				WRONG = true;
				break;
			}
			if(A[i] != B[i]){
				MISMATCH = true;
			}
		}
		if(WRONG || !MISMATCH)
			printf("no\n");
		else
			printf("yes\n");
	}

	return 0;
}