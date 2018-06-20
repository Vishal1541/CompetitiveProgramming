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
#define us unordered_set
#define um unordered_map
#define mii map<Int,Int>
#define qi queue<Int>
#define pb push_back
#define MOD 1000000007
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define PI 3.141592653589793238L
#define F first
#define S second
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define mp make_pair
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int N,M,D,a,b,Max=10000000000,ans=0,fin;

Int max(Int a,Int b){
	return a>b?a:b;
}
Int min(Int a,Int b){
	return a<b?a:b;
}

int main(){
	ios;
	cin>>N>>M>>D;
	vi arr(N+1),depend(N+1,Max);
	fl(i,1,N+1)	cin>>arr[i];
	while(M--){
		cin>>a>>b;
		if(b<depend[a])	depend[a]=b;
	}
	depend[0]=0;
	fin=N;
	fl(i,1,N+1){
		ans+=arr[i]-arr[i-1];
		if(depend[i]!=Max){
			if(i!=N)
				ans+=2*(arr[i]-arr[depend[i]]);
			else{
				ans+=(arr[i]-arr[depend[i]]);
				fin=depend[i];
			}
		}
	}
	ans+=max(arr[fin],D)-min(arr[fin],D);
	cout<<ans<<endl;

	return 0;
}