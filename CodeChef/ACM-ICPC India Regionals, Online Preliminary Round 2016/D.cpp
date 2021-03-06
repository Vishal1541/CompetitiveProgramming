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


int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	vvi sieve(1000000);
	fl(i,1,750001){
		for(int j=2*i; j<=750001; j+=i){
			sieve[j].pb(i);	
		}
	}

	int t,n;
	cin>>t;
	while(t--){
		vi counter(1000000,1);
		Int ans = 0;
		cin>>n;
		vi arr(n), flag(1000000,0);
		fl(i,0,n){
			cin>>arr[i];
			flag[arr[i]] = 1;
		}
		sort(arr);
		fl(i,0,arr[n-1]+1){
			if(flag[i]){
				fl(j,0,sieve[i].size()){
					if(flag[sieve[i][j]])
						counter[i] = (counter[i]+counter[sieve[i][j]])%MOD;
				}
				ans = (ans+counter[i])%MOD;
			}
		}
		cout<<ans<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}