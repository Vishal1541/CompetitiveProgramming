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

int n;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>n;
	vi arr(n);
	fl(i,0,n)	cin>>arr[i];
	int idx1=-1,idx2=-1;
	fl(i,0,n)	if(arr[i]==1){idx1 = i-1;break;}
	for(int i=n-1; i>=0; i--)if(arr[i]==1){idx2 = i+1;break;}
	if(idx1==-1 && idx2==-1){
		cout<<"0";
		return 0;
	}
	vi zeros;
	fl(i,idx1+1,idx2){
		int z = 0;
		while(arr[i]==0){
			z++;
			i++;
			if(i>=idx2)	break;
		}
		zeros.pb(z);
	}
	sort(zeros);
	int ans = 0;
	for(int i=zeros.size()-1; i>=0; i--){
		if(zeros[i]>=2){
			ans += zeros[i];
		}
		else
			break;
	}
	ans = (n-(idx1+1+n-idx2))-ans;
	cout<<ans;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}