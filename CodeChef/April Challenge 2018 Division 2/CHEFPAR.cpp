#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int n,m,k;

int main(){
	cin>>n>>m>>k;
	for(int i=0; i<n; i++){
		int in;
		cin>>in;
		cout<<in+k/2<<" ";
	}

	return 0;
}