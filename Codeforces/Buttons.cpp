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

int n;

int main(){
	cin>>n;
	Int sum = 0;
	fl(i,1,n+1){
		sum += i*(n-i)+1;
	}
	cout<<sum;

	return 0;
}