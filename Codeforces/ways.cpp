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
	cout.precision(10);
	cout<<fixed;

	int n,s,ans = 0;
	cin>>n;
	vi arr(n),summ(n,0);
	vvi counter(3,vi(n) );
	fl(i,0,n){
		counter[0][i] = counter[1][i] = counter[2][i] = 0;
	}
	fl(i,0,n)	cin>>arr[i];
	summ[0] = arr[0];
	fl(i,1,n)	summ[i] = summ[i-1]+arr[i];
	s = summ[n-1]%3;
	if(s!=0){
		cout<<"0\n";
		return 0;
	}
	s = summ[n-1]/3;
	fl(i,0,n){
		if(summ[i]==s)	counter[0][i] = 1;
		if(summ[i]==2*s)	counter[1][i] = 1;
		if(summ[i]==3*s)	counter[2][i] = 1;
	}
	fl(i,1,n){
		counter[2][i] += counter[2][i-1];
	}
	fl(i,1,n){
		if(counter[1][i]==1){
			counter[1][i] = counter[2][n-1]-counter[2][i];
		}
	}
	for(int i=n-2; i>=0; i--){
		counter[1][i] += counter[1][i+1];
	}
	fl(i,0,n-2){
		if(counter[0][i]==1){
			ans += counter[1][i+1];
		}
	}
	cout<<ans<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}