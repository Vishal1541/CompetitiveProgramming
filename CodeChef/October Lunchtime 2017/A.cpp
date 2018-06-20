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

int t;
string a,b;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a.length()<b.length())	swap(a,b);
		int ans = 0;
		int mul = 1;
		int c; 
		for(int i=b.length()-1; i>=0; i--){
			c = a[i+a.length()-b.length()]+b[i]-'0'-'0';
			c %= 10;
			ans += c*mul;
			mul *= 10;
		}
		for(int i=a.length()-b.length()-1; i>=0; i--){
			ans += (a[i]-'0')*mul;
			mul *= 10;
		}
		cout<<ans<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}