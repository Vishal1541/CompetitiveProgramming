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

Int n,size = 100009;
vi arr(size),asc(size,0),desc(size,0),Costa(size,0),Costd(size,0),finalarr;

int main(){
	ios;
	cin>>n;
	fl(i,1,n+1){
		cin>>arr[i];
	}
	asc[1] = arr[1];
	fl(i,2,n+1){
		if(arr[i]>asc[i-1])	asc[i] = arr[i];
		else 	asc[i] = asc[i-1]+1;
	}
	desc[n] = arr[n];
	for(int i=n-1; i>=0; i--){
		if(arr[i]>desc[i+1])	desc[i] = arr[i];
		else 	desc[i] = desc[i+1]+1;
	}
	fl(i,1,n+1){
		Costa[i] = Costa[i-1] + asc[i] - arr[i];
	}
	for(int i=n; i>=0; i--){
		Costd[i] = Costd[i+1] + desc[i] - arr[i];
	}
	Int ans = Costd[1];
	finalarr.pb(ans);
	fl(i,1,n){
		// if(Costa[i]+Costd[i+1]<ans)	ans = Costa[i] + Costd[i+1];
		if(asc[i] == desc[i+1])	finalarr.pb(Costa[i]+Costd[i+1]+1);
		else	finalarr.pb(Costa[i]+Costd[i+1]);
	}
	sort(finalarr);
	cout<<finalarr[0]<<endl;

	return 0;
}