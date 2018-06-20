//    VISHAL ANAND
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <functional>

using namespace std;

#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define us unordered_set
#define um unordered_map
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());

int T,N;

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		si_d s;
		fl(i,0,N){
			int input;
			cin>>input;
			s.insert(input);
		}
		if(s.size()==1){
			cout<<"0\n";
			continue;
		}
		si_d :: iterator itr = s.begin();
		itr++;
		cout<<*itr<<endl;
	}

	return 0;
}