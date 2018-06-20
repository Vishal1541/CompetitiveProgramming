//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int unsigned long long int
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

Int T,N,P,modd = 1000000007;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>T;
	while(T--){
		cin>>N;
		Int ans = 1;
		vi arr(N+1), flag(100009,0);
		fl(i,1,N+1){
			cin>>arr[i];
		}
		fl(i,1,N+1){
				Int cnt = 1;
				Int c = arr[i];
				while(c!=i){
					c = arr[c];
					cnt++;
				}
				ans = ((((ans)*(cnt)))/((gcd(ans,cnt))));
		}
		ans = ans%modd;
		cout<<ans<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}