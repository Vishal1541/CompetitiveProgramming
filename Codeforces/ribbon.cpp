//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > dp(5, vector<int> (5000) );

int main(){
	std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	int arr[5];
	cin>>n;
	for(int i=1; i<=3; i++)	cin>>arr[i];
		sort(arr+1,arr+4);
	for(int i=1; i<=3; i++){
		if(arr[i]==1){
			while(i<=3)
				dp[i++][1] = 1;
		}
	}
	for(int j=2; j<=n; j++){
		for(int i=1; i<=3; i++){
			if(j-arr[i]<0)	dp[i][j] = dp[i-1][j];
			else if(j-arr[i]==0) dp[i][j] = max(1+dp[3][j-arr[i]],dp[i-1][j]);
			else	dp[i][j] = max((dp[3][j-arr[i]]==0?0:1+dp[3][j-arr[i]]),dp[i-1][j]);
		}
	}
	cout<<dp[3][n];
	return 0;
}