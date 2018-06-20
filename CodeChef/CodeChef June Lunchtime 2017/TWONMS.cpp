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

#define Int unsigned long long int
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

Int T,A,B,N;

int main(){
	cin>>T;
	while(T--){
		cin>>A>>B>>N;
		Int A_FINAL, B_FINAL;
		Int a_power, b_power;
		if(N%2){
			cout<<(Int)max(2*A,B)/(Int)min(2*A,B)<<endl;
		}
		else{
			cout<<(Int)max(A,B)/(Int)min(A,B)<<endl;
		}
	}

	return 0;
}