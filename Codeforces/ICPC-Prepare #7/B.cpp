//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(int i=x; i<y; i++)
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

int t,k,a,b;
vi dp(100009,0), sum(100009,0);

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>t>>k;
	dp[0] = 1;
	fl(i,1,k)	dp[i] = 1;
	fl(i,k,100009)	dp[i] = (dp[i-1] + dp[i-k])%MOD;
	fl(i,1,100009)	sum[i] = (sum[i-1] + dp[i])%MOD;
	while(t--){
		cin>>a>>b;
		cout<<((sum[b]-sum[a-1])<0?sum[b]-sum[a-1]+MOD:sum[b]-sum[a-1])<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}