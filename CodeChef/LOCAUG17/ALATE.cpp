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
#define MOD 1e9+7
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

Int T,N,Q,x,y;
Int mod = 1e+7;

void run(){
	cin>>N>>Q;
	Int arr[N+1],arr2[N+1],type;
	fl(i,1,N+1)	{cin>>arr[i];arr2[i]=((arr[i]%mod)*(arr[i]%mod))%mod;}
	while(Q--){
		cin>>type;
		if(type-1){
			cin>>x>>y;
			arr[x]=y;
			arr2[x]=((y%mod)*(y%mod))%mod;
		}
		else{
			cin>>x;
			Int sum=0;
			for(int i=x; i<=N; i+=x){
				sum = (sum%mod + arr2[i]%mod)%mod;
			}
			cout<<sum<<endl;
		}
	}
}

int main(){
	ios;
	cin>>T;
	while(T--){
		run();
	}

	return 0;
}
