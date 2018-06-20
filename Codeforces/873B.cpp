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

Int Max(Int a, Int b){
	return (a>b?a:b);
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	int n,ans = -1;
	string s;
	mii indices;
	indices[0] = -1;
	cin>>n>>s;
	vi ones(n), zeros(n), diff(n);
	if(s[0]=='1'){
		ones[0] = 1;
		zeros[0] = 0;
	}
	else{
		ones[0] = 0;
		zeros[0] = 1;
	}
	fl(i,1,n){
		if(s[i]=='1'){
			ones[i] = ones[i-1]+1;
			zeros[i] = zeros[i-1];
		}
		else{
			ones[i] = ones[i-1];
			zeros[i] = zeros[i-1]+1;
		}
	}
	fl(i,0,n){
		diff[i] = ones[i]-zeros[i];
	}
	fl(i,0,n){
		if(indices.find(diff[i])==indices.end()){
			indices[diff[i]] = i;
		}
		else{
			ans = Max(ans,i-indices[diff[i]]);
		}
	}
	cout<<(ans>0?ans:0)<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}