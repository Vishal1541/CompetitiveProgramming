//    VISHAL ANAND
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

int t,n,m;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>t;
	while(t--){
		cin>>n>>m;
		if(n==1)	cout<<"0\n";
		else if(n==2)	cout<<m<<endl;
		else{
			vi arr(n-1,0);
			Int counter = 0;
			bool last;
			while(arr[0]!=m){
				last = false;
				counter++;
				fl(i,0,n-2){
					if(arr[i]!=arr[i+1]){
						if(i==n-3){
							last = true;
						}
						arr[i]++;i++;
					}
				}
				if(!last && arr[n-2]<m)	arr[n-2]++;
			}
			cout<<counter<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}