//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

int n;
void Copy(int* arr, int* arr2){
	for(int i=0; i<n; i++){
		arr2[i] = arr[i];
	}
}

void flip(int* arr, int i, int j){
	for(int idx=i; idx<=j; idx++)
		arr[idx] = 1-arr[idx];
}

int main(){
	std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	int arr[n],arr2[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	int ones = 0, temp;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			temp = 0;
			Copy(arr,arr2);
			flip(arr2,i,j);
			for(int k=0; k<n; k++)
				if(arr2[k]==1)
					temp++;
			ones = max(ones, temp);
		}
	}
	cout<<ones;

	return 0;
}