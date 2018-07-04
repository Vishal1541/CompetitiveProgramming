// VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

int n,inp,ans;
stack<int> s;
set<int> distinct;

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>inp;
		bool ins = 0;
		set<int> temp;
		if(s.empty()){
			s.push(inp);
		}
		while(!s.empty() && s.top() > inp){
			// ans++;
			temp.insert(s.top());
			ins = 1;
			s.pop();
		}
		// if(ins)	ans++;
		ans += temp.size();
		s.push(inp);
	}
	while(!s.empty()){
		distinct.insert(s.top());
		s.pop();
	}
	ans += distinct.size();
	cout<<ans;

	return 0;
}