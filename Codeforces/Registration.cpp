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
#define si_d set<Int, greater<Int> >
#define us unordered_set
#define um unordered_map
#define pb push_back
#define MOD 1e9+7

int n;

int main(){
	cin>>n;
	pair <string,int> p;
	um<string,int> s;
	um<string,int> :: iterator itr;
	fl(i,0,n){
		string str;
		cin>>str;
		itr = s.find(str);
		if(itr==s.end()){
			cout<<"OK"<<endl;
			s.insert(pair<string,int>(str,1));
			continue;
		}
		int add = itr->second;
		(itr->second)++;
		string str2 = str;
		str2.append(to_string(add));
		cout<<str2<<endl;
		s.insert(pair<string,int>(str2,1));
	}


	return 0;
}