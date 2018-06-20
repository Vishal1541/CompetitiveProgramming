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

	int n,m;
	cin>>n>>m;
	vi arr1(n), arr2(m);
	fl(i,0,n)	cin>>arr1[i];
	fl(i,0,m)	cin>>arr2[i];
	sort(arr1);
	sort(arr2);
	int a = arr1[0];
	int b = arr2[0];
	bool found = false;
	vi ans;
	fl(i,0,n){
		fl(j,0,m){
			if(arr1[i]==arr2[j])	ans.pb(arr1[i]);
		}
	}
	ans.pb(arr1[0]*10+arr2[0]);
	ans.pb(arr2[0]*10+arr1[0]);
	sort(ans);
	cout<<ans[0]<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}