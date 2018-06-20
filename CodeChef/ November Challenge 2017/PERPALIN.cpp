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

int T,N,P;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>T;
	while(T--){
		cin>>N>>P;
		vector<char> arr(N);
		vi flag(2,0);
		fl(i,0,N)	arr[i] = 'x';
		for(int i=0; i<N; i+=P)	arr[i] = 'a';
		if(arr[N-1]=='x')
			for(int i=N-1; i>=0; i-=P)	arr[i] = 'a';
		fl(i,0,N)	if(arr[i]=='x')	arr[i] = 'b';
		fl(i,0,N)	flag[arr[i]-'a'] = 1;
		if(flag[0] && flag[1]){
			fl(i,0,N)	cout<<arr[i];
			cout<<endl;
		}
		else cout<<"impossible\n";
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}