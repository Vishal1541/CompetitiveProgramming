//VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(int i=x; i<y; i++)
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

	int a,b,ans=0;
	cin>>a>>b;
	int ar[1000001]={0};
	int br[1000001]={0};
	for(int i=0; i<a; i++){
		cin>>ar[i]>>br[i];;
	}
	bool idx[100001]={0};
	idx[0] = 1;
	for(int i=0; i<a; i++){
		if(idx[ar[i]]==1){
			for(int j=ar[i]; j<=br[i]; j++)
				idx[j] = 1;
		}
		else
			break;
	}
	if(idx[b]==1)	cout<<"YES";
	else 	cout<<"NO";

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}
