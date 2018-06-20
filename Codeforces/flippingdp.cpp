//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	int arr[n],score[n],dp[n],ones = 0;
	for(int i=0; i<n; i++)	cin>>arr[i];
	for(int i=0; i<n; i++){
		if(arr[i]==1){
			score[i] = -1;
			ones++;
		}
		else 	score[i] = 1;
	}
	dp[0] = 1-arr[0];
	for(int i=1; i<n; i++){
		dp[i] = max(dp[i-1],score[i]+dp[i-1]);
	}
	cout<<ones+dp[n-1];

	return 0;
}