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
	int n;
	cin>>n;
	int arr1[n],arr2[n],arr3[n],miss1=0,miss2=0;
	mii m1,m2,m3;
	fl(i,0,n){
		cin>>arr1[i];
		m1[arr1[i]]++;
	}
	fl(i,0,n-1){
		cin>>arr2[i];
		m2[arr2[i]]++;
	}
	fl(i,0,n-2){
		cin>>arr3[i];
		m3[arr3[i]]++;
	}
	fl(i,0,n){
		if(m2[arr1[i]]==m1[arr1[i]]-1){
			miss1 = arr1[i];
			break;
		}
	}
	fl(i,0,n-1){
		if(m3[arr2[i]]==m2[arr2[i]]-1){
			miss2 = arr2[i];
			break;
		}
	}
	cout<<miss1<<endl<<miss2<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}