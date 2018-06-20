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

int n;

int main(){
	cin>>n;
	string str;
	while(n--){
		cin>>str;
		int len = str.length();
		if(len<=10){
			cout<<str<<endl;
			continue;
		}
		cout<<str[0]<<len-2<<str[len-1]<<endl;
	}

	return 0;
}