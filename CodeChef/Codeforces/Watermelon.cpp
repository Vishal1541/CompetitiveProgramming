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

int main(){
	int n;
	cin>>n;
	if(!(n%2) && n!=2){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");

	return 0;
}