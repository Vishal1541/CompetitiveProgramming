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

	Int n, sum = 0, ans = 0, cnt = 1;
	cin>>n;
	vi arr(n), left, right_count(n,0);
	si right;
	si_it itr;
	fl(i,0,n){
		cin>>arr[i];
		sum += arr[i];
	}
	if((double)sum/3 != sum/3){
		cout<<"0\n";
		return 0;
	}
	Int ptr1 = 0, ptr2 = n-1, s2 = 0;
	fl(i,0,n){
		s2 += arr[i];
		if(s2==sum/3)	left.pb(i);
	}
	s2 = 0;
	for(Int i=n-1; i>=0; i--){
		s2 += arr[i];
		if(s2==sum/3){
			right.insert(i);
			right_count[i] = cnt++;
		}
	}
	fl(i,0,left.size()){
		itr = right.lower_bound(left[i]+2);
		if(itr!=right.end()){
			ans += right_count[*itr];
		}
	}
	cout<<ans<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}