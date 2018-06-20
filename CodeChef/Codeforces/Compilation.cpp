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

int main(){
	int n;
	cin>>n;
	msi a,b,c;
	int input;
	fl(i,0,n){
		cin>>input;
		a.insert(input);
	}
	fl(i,0,n-1){
		cin>>input;
		b.insert(input);
	}
	fl(i,0,n-2){
		cin>>input;
		c.insert(input);
	}
	msi_it ita, itb, itc;
	bool ALL_EQUAL = true;
	ita = a.begin();
	for(itb=b.begin(); itb!=b.end(); itb++){
		if(*itb==*ita){
			ita++;
			continue;
		}
		cout<<*ita<<endl;
		ALL_EQUAL = false;
		break;
	}
	if(ALL_EQUAL)
		cout<<*ita<<endl;
	ALL_EQUAL = true;
	itb = b.begin();
	for(itc=c.begin(); itc!=c.end(); itc++){
		if(*itb==*itc){
			itb++;
			continue;
		}
		cout<<*itb<<endl;
		ALL_EQUAL = false;
		break;
	}
	if(ALL_EQUAL)
		cout<<*itb<<endl;

	return 0;
}