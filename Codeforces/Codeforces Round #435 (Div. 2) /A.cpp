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

int main(){
	ios;
	Int n,x,ans=0;
	cin>>n>>x;
	vi arr(n),flag(x+1,0);
	fl(i,0,n)	cin>>arr[i];
	sort(arr);
	fl(i,0,n){
		if(arr[i]>x)	break;
		flag[arr[i]] = 1;
	}
	fl(i,0,x){
		if(flag[i]==0)	ans++;
	}
	if(flag[x]==1)	ans++;
	cout<<ans<<endl;

	return 0;
}