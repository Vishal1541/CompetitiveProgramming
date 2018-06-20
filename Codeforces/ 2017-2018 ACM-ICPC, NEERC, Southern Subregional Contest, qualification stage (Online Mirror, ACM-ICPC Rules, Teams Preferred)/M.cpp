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

Int n,diff;
bool isAP = true;

int main(){
	ios;
	cin>>n;
	vi arr(n);
	fl(i,0,n)	cin>>arr[i];
	diff = arr[1]-arr[0];
	fl(i,2,n){
		if(arr[i]-arr[i-1] != diff){
			isAP = false;
			break;
		}
	}
	if(isAP)	cout<<arr[n-1]+diff;
	else 	cout<<arr[n-1];

	return 0;
}