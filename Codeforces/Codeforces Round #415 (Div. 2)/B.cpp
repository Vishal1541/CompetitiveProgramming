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

Int n,f,before = 0;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>n>>f;
	vi extra;
	Int kl[n][2];
	fl(i,0,n){
		cin>>kl[i][0]>>kl[i][1];
		if(kl[i][0]>=kl[i][1]){
			before += kl[i][1];
		}
		else{
			before += kl[i][0];
			if(kl[i][0]*2>=kl[i][1])	extra.pb(kl[i][1]-kl[i][0]);
			else 	extra.pb(kl[i][0]);
		}
	}
	sort(extra);
	for(int i=extra.size()-1; i>extra.size()-1-f; i--){
		if(i<0)	break;
		before += extra[i];
	}
	cout<<before<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}