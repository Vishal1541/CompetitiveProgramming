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

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	int n,k;
	cin>>n>>k;
	vi arr(n), minn;
	fl(i,0,n)	cin>>arr[i];
	sort(arr);
	minn.pb(arr[k-1]-arr[0]);
	int i = k, left = arr[0], last = arr[n-1]-arr[n-k];
	while(i<n){
		if(i>=n-k){
			minn.pb(last);
			break;
		}
		if(i+k-1>=n-k){
			if(arr[i]-left<arr[n-1]-arr[i]){
				minn[minn.size()-1] = arr[i]-left;
				i++;
			}
			else{
				minn.pb(arr[n-1]-arr[i]);
				break;
			}
		}
		else if(arr[i]-left<arr[min(n-1,i+k-1)]-arr[i]){
			minn[minn.size()-1] = arr[i]-left;
			i++;
		}
		else{
			minn.pb(arr[min(n-1,i+k-1)]-arr[i]);
			i += k;
			left = arr[i];
		}
	}
	sort(minn);
	cout<<minn[minn.size()-1]<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}