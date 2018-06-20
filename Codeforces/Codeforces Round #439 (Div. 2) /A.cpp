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
#define MOD 1000000007
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

vi flag(20000000,0);

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	int n;
	cin>>n;
	vi arr1(n),arr2(n);
	fl(i,0,n){
		cin>>arr1[i];
		flag[arr1[i]] = 1;
	}
	fl(i,0,n){
		cin>>arr2[i];
		flag[arr2[i]] = 1;
	}
	Int ans = 0;
	fl(i,0,n){
		fl(j,0,n){
			if(flag[arr1[i]^arr2[j]]==1){
				ans++;
			}
		}
	}
	cout<<(ans%2==0?"Karen\n":"Koyomi\n");

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}