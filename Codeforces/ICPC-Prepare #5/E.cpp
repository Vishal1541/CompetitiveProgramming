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
int k;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>s>>k;
	if(s.length()%k!=0){
		cout<<"NO\n";
		return 0;
	}
	vi arr(k+1);
	int mul = 0;
	fl(i,0,k+1){
		arr[i] = mul*(s.length()/k);
		mul++;
	}
	bool yes = true;
	fl(i,0,k){
		fl(j,0,s.length()/k){
			if(s[arr[i]+j]!=s[arr[i+1]-j-1]){
				yes = false;
			}
		}
	}
	cout<<(yes?"YES":"NO");

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}