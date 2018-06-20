#include<bits/stdc++.h>

using namespace std;

int main(){
	map<int,int> mp;
	map<int,int> :: iterator it;
	int n;
	cin>>n;
	while(n--){
		int num;
		cin>>num;
		mp[num]++;
	}
	it = mp.begin();
	int x = it->second;
	int p = it->first;
	it++;
	int y = it->second;
	int q = it->first;
	if(mp.size()==2 && x==y) cout<<"YES"<<p<<q;
	else cout<<"NO";

	return 0;
}