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

int N,Q,K,sum = 0, subtracted = 0, Minus = 0;
vi dp(100009);

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>N;
	vi arr(N);
	fl(i,0,N){
		cin>>arr[i];
		sum += arr[i];
	}
	sort(arr);
	dp[0] = sum;
	int ptr = N-1;
	fl(k,1,N){
		while(N-ceil((double)N/(k+1))>Minus){
			subtracted += arr[ptr--];
			Minus++;
		}
		dp[k] = sum-subtracted;
	}
	cin>>Q;
	while(Q--){
		cin>>K;
		cout<<dp[K]<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}