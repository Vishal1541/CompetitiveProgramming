#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int t,n;

int main(){
	cin>>n;
	int trans, writer, both, arr[n];
	trans = writer = both = 10000000;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		int type;
		cin>>type;
		if(type==1)	trans = min(trans,arr[i]);
		else if(type==2)	writer = min(writer,arr[i]);
		else 	both = min(both,arr[i]);
	}
	cout<<min(both,trans+writer)<<endl;

	return 0;
}