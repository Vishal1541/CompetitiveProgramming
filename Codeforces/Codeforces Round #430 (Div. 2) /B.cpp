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
#define us unordered_set
#define um unordered_map
#define mii map<Int,Int>
#define qi queue<Int>
#define pb push_back
#define MOD 1000000007
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define PI 3.141592653589793238L
#define F first
#define S second
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define mp make_pair
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int r,d,n,xi,yi,ri;

int main(){
	ios;
	cin>>r>>d>>n;
	int arr[n][3];
	fl(i,0,n)	cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	double d1,d2,d3;
	Int ans=0;
	fl(i,0,n){
		xi=arr[i][0];
		yi=arr[i][1];
		ri=arr[i][2];
		d1 = sqrt(xi*xi+yi*yi);
		d2 = d1-ri;
		d3 = d1+ri;
		if(d2>=(r-d) && d3<=(r) )	ans++;
	}
	cout<<ans<<endl;

	return 0;
}