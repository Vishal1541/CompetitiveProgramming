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

Int n,inp,idx,nxt=1;

Int search(vi& max_store, Int val){
	Int l = 1, h = n, m;
	while(l<h){
		m = (l+h)/2;
		if(max_store[m]>=val)	l = m+1;
		else	h = m-1;
	}
	if(max_store[l]>=val)	return l+1;
	return l;
}

int main(){
	ios;
	cin>>n;
	vi arr(n+1),max_store(n+2,0);
	vvi store(n+2);
	fl(i,1,n+1)	cin>>arr[i];
	fl(i,1,n+1){
		idx = search(max_store, arr[i]);
		store[idx].pb(arr[i]);
		max_store[idx] = arr[i];
	}
	while(store[nxt].size()>0){
		fl(i,0,store[nxt].size())
			cout<<store[nxt][i]<<" ";
		cout<<endl;
		nxt++;
	}

	return 0;
}