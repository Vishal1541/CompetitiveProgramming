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

Int t,y;
si store;
vi AA,BB;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>t;
	while(t--){
		store.clear();
		AA.clear();
		BB.clear();
		cin>>y;
		if(y==1){
			cout<<"0\n";
			continue;
		}
		Int bb;
		if(y>700)	bb=700;
		else bb=y-1;
		Int ans = 0;
		while(bb>=1){
			Int aa = sqrt(y-bb);
			if(aa>0 && store.find(aa)==store.end()){
				// if(y-aa*aa<=700)
				// 	ans += (y-aa*aa)*aa;
				// else
				// 	ans += 700*aa;
				store.insert(aa);
				AA.pb(aa);
				if(y-aa*aa>700)
					BB.pb(700);
				else
					BB.pb(y-aa*aa);
			}
			bb--;
		}
		if(AA.size()==1){
			cout<<BB[0]*AA[0]<<endl;
		}
		else{
			Int ans = BB[0]*AA[0];
			fl(i,1,AA.size()){
				ans += BB[i]*(AA[i]-AA[i-1]);			
			}
			cout<<ans<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}