#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		map<char,ll> m;
		map<char,ll> :: iterator itr;
		cin>>s;
		for(int i=0; i<s.length(); i++){
			m[s[i]]++;
		}
		vector<ll> arr;
		for(itr=m.begin(); itr!=m.end(); itr++){
			arr.push_back(itr->second);
		}
		sort(arr.begin(), arr.end());
		if(arr.size()<3){
			cout<<"Dynamic\n";
		}
		else{
			bool yes = 1;
			for(int i=2; i<arr.size(); i++){
				if(i==3){
					if(arr[i] == arr[i-1] + arr[i-2] ||
						arr[i] == arr[i-1] + arr[i-3])
						continue;
					else{
						yes = 0;
						break;
					}
				}
				else{
					if(arr[i] != arr[i-1] + arr[i-2]){
						yes = 0;
						break;
					}
				}
			}
			cout<<(yes?"Dynamic\n":"Not\n");
		}
	}

	return 0;
}