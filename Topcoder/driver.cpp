//    VISHAL ANAND
#include "bits/stdc++.h"
#include "Substitute.cpp"
using namespace std;

string key,code;

int main(){
	Substitute s;
	int t = 3;
	while(t--){
		cin>>key>>code;
		int ans = s.getValue(key,code);
		cout<<"Returns: "<<ans<<endl;
	}
	return 0;
}