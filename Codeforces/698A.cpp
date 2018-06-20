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

vvi dp(120,vi(5));

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	int n;
	cin>>n;
	vi arr(n);
	fl(i,0,n)	cin>>arr[i];
	dp[0][0] = 0;
	if(arr[0]==1 || arr[0]==3)	dp[0][1] = 1;
	if(arr[0]==2 || arr[0]==3)	dp[0][2] = 1;
	dp[0][3] = max(dp[0][0],max(dp[0][1],dp[0][2]));
	fl(i,1,n){
		dp[i][0] = dp[i-1][3];
		dp[i][1] = max(dp[i-1][0],dp[i-1][2]);
		dp[i][2] = max(dp[i-1][0],dp[i-1][1]);
		if(arr[i]==1 || arr[i]==3)	dp[i][1]++;
		if(arr[i]==2 || arr[i]==3)	dp[i][2]++;
		dp[i][3] = max(dp[i][0],max(dp[i][1],dp[i][2]));
	}

	cout<<n-dp[n-1][3]<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}