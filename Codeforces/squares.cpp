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
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int inp1,inp2;
vvi a(3);

bool cmp(const vi& a, const vi& b){
	return a[0]>b[0];
}

int main(){
	ios;
	cin>>inp1>>inp2;
	a[0].pb(max(inp1,inp2));
	a[0].pb(min(inp1,inp2));

	cin>>inp1>>inp2;
	a[1].pb(max(inp1,inp2));
	a[1].pb(min(inp1,inp2));

	cin>>inp1>>inp2;
	a[2].pb(max(inp1,inp2));
	a[2].pb(min(inp1,inp2));

	sort(a.begin(),a.end(),cmp);

	bool yes = false;

	if(a[0][0]==a[1][0] && a[0][0]==a[2][0] && (a[0][1]+a[1][1]+a[2][1]==a[1][0]))
		yes = true;
	else{
		if(a[1][0]==a[2][0] && a[1][1]+a[2][1]==a[0][0] && a[1][0]+a[0][1]==a[0][0])
			yes = true;
		else if(a[1][1]==a[2][1] && a[1][0]+a[2][0]==a[0][0] && a[1][1]+a[0][1]==a[0][0])
			yes = true;
		else if(a[1][0]==a[2][1] && a[1][1]+a[2][0]==a[0][0] && a[1][0]+a[0][1]==a[0][0])
			yes = true;
		else if(a[1][1]==a[2][0] && a[1][0]+a[2][1]==a[0][0] && a[1][1]+a[0][1]==a[0][0])
			yes = true;
	}
	cout<<(yes?"YES\n":"NO\n");

	return 0;
}