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
#define vi vector<Int,Int>
#define si set<Int>
#define si_d set<Int, greater<Int> >
#define msi multiset<Int>
#define msi_d multiset<Int, greater<Int> >

int main(){
	string str;
	cin>>str;
	int len = str.length();
	msi s;
	fl(i,0,len){
		s.insert((int)(str[i]-'0'));
		i++;
	}
	msi :: iterator itr;
	for(itr = s.begin(); itr!=s.end(); itr++){
		if(itr==s.begin()){
			printf("%lld",*itr);
			continue;
		}
		printf("+%lld",*itr);
	}
	printf("\n");

	return 0;
}