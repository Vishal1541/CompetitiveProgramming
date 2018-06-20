//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int n,m,k,score = 0, replace = 0;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>n>>m>>k;
	vvi arr(n,vi(m));
	fl(i,0,n)	fl(j,0,m)	cin>>arr[i][j];
	fl(j,0,m){
		int k_ = 0, below = n-1, above = n-1, ones = 0;
		while(k_!=k){
			if(arr[above][j]==1)	ones++;
			above++,k_++;
		}
		above--;
		int ones_ = ones;
		while(above>0){
			above--,below--;
			if(arr[above][j]==1)	ones_++;
			if(arr[below+1][j]==1)	ones_--;
			ones = max(ones,ones_);
		}
		score += ones;
		while(ones_!=ones){
			above++,below++;
			if(arr[above-1][j]==1)	ones_--;
			if(arr[below][j]==1)	ones_++;
		}
		above--;
		while(above>=0){
			if(arr[above][j]==1)	replace++;
			above--;
		}
	}
	cout<<score<<" "<<replace<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}