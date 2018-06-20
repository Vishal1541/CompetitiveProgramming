//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<int> arr(m);
	for(int i=0; i<m; i++)	cin>>arr[i];
	sort(arr.begin(), arr.end());
	int b=0, f=n-1;
	int minn = 10000;
	while(f<m){
		if(arr[f]-arr[b]<minn)	minn = arr[f]-arr[b];
		f++,b++;
	}
	cout<<minn;
}