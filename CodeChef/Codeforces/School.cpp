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
#define pb push_back
#define MOD 1e9+7

int n,t;

int main(){
	cin>>n>>t;
	vi arr;
	fl(i,0,n){
		char ch;
		cin>>ch;
		if(ch=='B')
			arr.pb(1);
		else
			arr.pb(0);
	}
	vi arr2(n);
	copy(arr.begin(),arr.end(),arr2.begin());
	fl(j,0,t){
		fl(i,0,n-1){
			if(arr[i]==1 && arr[i+1]==0){
				arr2[i]=0;
				arr2[i+1]=1;
			}
		}
		copy(arr2.begin(),arr2.end(),arr.begin());
	}
	fl(i,0,n){
		if(arr[i]==1)
			printf("B");
		else
			printf("G");
	}

	return 0;
}