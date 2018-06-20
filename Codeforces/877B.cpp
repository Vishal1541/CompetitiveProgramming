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

string s;
vi as(5009,0), bs(5009,0);
Int ans = 0;

Int max(Int a, Int b){
	return a>b?a:b;
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>s;
	fl(i,0,s.length()){
		if(s[i]=='a')	as[i+1] = as[i]+1, bs[i+1] = bs[i];
		else 	as[i+1] = as[i], bs[i+1] = bs[i] + 1;
	}
	fl(i,1,s.length()+2){
		Int a = as[i-1], b=0, a2=0;
		fl(j,i,s.length()+1){
			b = bs[j]-bs[i-1];
			a2 = as[s.length()]-as[j];
			// ans = max(ans,as[i-1]+bs[j]-bs[i-1]+as[s.length()]-as[j]);
			ans = max(ans,a+b+a2);
		}
		ans = max(ans,a+b+a2);
	}
	cout<<ans;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}