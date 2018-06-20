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

Int T,n,q,t;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>T;
	while(T--){
		cin>>n;
		vvi arr(n,vi(4));
		fl(i,0,n)	cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
		cin>>q;
		while(q--){
			cin>>t;
			Int x = t, x2 = t*t, x3 = t*t*t;
			Int ans = arr[0][0]+x*arr[0][1]+x2*arr[0][2]+x3*arr[0][3];
			fl(i,1,n){
				if(arr[i][0]+x*arr[i][1]+x2*arr[i][2]+x3*arr[i][3]<ans)
					ans = arr[i][0]+x*arr[i][1]+x2*arr[i][2]+x3*arr[i][3];
			}
			cout<<ans<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}