#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define si set<Int>
#define si_d set<Int, greater<Int> >
#define MOD 1e9+7

int main(){
	Int n,l;
	cin>>n>>l;
	l *= 1e10;
	si s;
	fl(i,0,n){
		Int input;
		cin>>input;
		input *= 1e10;
		s.insert(input);
	}
	long double radius, r_temp;
	if(n==1){
		radius = *s.begin()-0;
		if(l-*s.begin()>radius)
			radius = l-*s.begin();
		radius /= 1e10;
		cout<<radius;
		return 0;
	}
	si :: iterator itr,LAST = s.end(), ahead;
	LAST--;
	for(itr=s.begin(); itr!=LAST; itr++){
		ahead = ++itr;
		itr--;
		if(itr==s.begin() && *itr==0){
			radius = (long double)(*ahead)/2.0-(long double)(*itr)/2.0;
		}
		else if(itr==s.begin() && *itr!=0){
			radius = *itr;
		}
		r_temp = (long double)(*ahead)/2.0-(long double)(*itr)/2.0;
		if(r_temp>radius)
			radius = r_temp;
	}
	if(*itr!=l){
		r_temp = l-*itr;
		if(r_temp>radius)
			radius = r_temp;
	}
	radius /= 1e10;
	cout<<radius;

	return 0;
}