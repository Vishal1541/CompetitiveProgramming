#include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> arr1(n),arr2(n);
		for(int i=0; i<n; i++){
			cin>>arr1[i];
		}
		for(int i=0; i<n; i++){
			cin>>arr2[i];
		}
		sort(arr1.begin(), arr1.end());
		sort(arr2.begin(), arr2.end());
		int A = 0, B = 0;
		for(int i=0; i<n-1; i++)	A += arr1[i];
		for(int i=0; i<n-1; i++)	B += arr2[i];
		if(A<B){
			cout<<"Alice\n";
		}
		else if(A>B){
			cout<<"Bob\n";
		}
		else{
			cout<<"Draw\n";
		}
	}

	return 0;
}