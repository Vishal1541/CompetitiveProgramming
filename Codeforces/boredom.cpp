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
#define MOD 1000000007
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

vi counter(100009,0),memo(100009,-1);

Int max(Int a,Int b){
	return (a>b?a:b);
}

Int opt(Int i){
	if(i==0)	return 0;
	if(i==1)	return counter[1];
	if(memo[i]!=-1)	return memo[i];
	return memo[i] = max(opt(i-1), opt(i-2)+i*counter[i]);
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	Int n,inp,M=-1;
	cin>>n;
	fl(i,0,n){
		cin>>inp;
		if(inp>M)	M = inp;
		counter[inp]++;
	}
	Int ans = opt(M);
	cout<<ans;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}