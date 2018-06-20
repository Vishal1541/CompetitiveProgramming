//VISHAL ANAND
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

int h1,a1,c1,h2,a2;
vector<string> ans;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>h1>>a1>>c1>>h2>>a2;
	while(h2>0){
		h2 -= a1;
		h1 -= a2;
		if(h2<=0){
			ans.pb("STRIKE");
			break;
		}
		if(h1>0){
			ans.pb("STRIKE");
			continue;
		}
		h2 += a1;
		ans.pb("HEAL");
		h1 += c1;
	}
	cout<<ans.size()<<endl;
	fl(i,0,ans.size())	cout<<ans[i]<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}
