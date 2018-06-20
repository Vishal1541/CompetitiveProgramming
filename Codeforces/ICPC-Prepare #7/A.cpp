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

int n;
vi A(109,0);
vvi dp(2,vi(109));

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n;
	fl(i,1,n+1)	cin>>A[i];
	dp[0][0] = dp[1][0] = 0;
	fl(i,1,n+1){
		if(A[i]==0)	dp[0][i] = dp[1][i] = max(dp[0][i-1],dp[1][i-1]);
		else if(A[i]==1){
			dp[0][i] = max(dp[1][i-1]+1,max(dp[0][i-1],dp[1][i-1]));
			dp[1][i] = max(dp[0][i-1],dp[1][i-1]);
		}
		else if(A[i]==2){
			dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
			dp[1][i] = max(dp[0][i-1]+1,max(dp[0][i-1],dp[1][i-1]));
		}
		else{
			dp[0][i] = max(dp[1][i-1]+1,max(dp[0][i-1],dp[1][i-1]));
			dp[1][i] = max(dp[0][i-1]+1,max(dp[0][i-1],dp[1][i-1]));
		}
	}
	cout<<n-max(dp[0][n],dp[1][n])<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}