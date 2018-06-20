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

int N,P,K,L;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>N;
	while(N--){
		cin>>P>>K>>L;
		vvi arr(K);
		vi inp(L);
		fl(i,0,L)	cin>>inp[i];
		sort(inp);
		int i=0,trav=L-1;
		while(trav>=0){
			arr[i].pb(inp[trav]);
			trav--;
			i++;
			if(i==K) i=0;
		}
		Int ans = 0;
		fl(j,0,K){
			fl(k,0,arr[j].size()){
				ans += (k+1)*arr[j][k];
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}