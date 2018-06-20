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

Int n,k,Min=-1,Max=-1;

int main(){
	ios;
	cin>>n>>k;
	if(k>0 && k<n)	Min = 1;
	else	Min = 0;
	if(k>=(n/2))	Max = n-k;
	else{
		if(k==0)	Max = 0;
		else	Max = (3*k>n)?n-k:2*k;
	}
	if(k==0){
		Min = Max = 0;
	}
	cout<<Min<<" "<<Max<<endl;

	return 0;
}