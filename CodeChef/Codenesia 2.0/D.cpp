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

int n,q,u,v,s,m,type;

void dfs(auto& tree, int node, auto& sal, auto& visited, auto& incr, Int prv){
	visited[node] = 1;
	sal[node] += prv+incr[node];
	fl(i,0,tree[node].size()){
		if(!visited[tree[node][i]])
			dfs(tree, tree[node][i], sal, visited, incr, prv+incr[node]);
	}
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n>>q;
	vvi tree(n);
	vi sal(n),incr(n,0);
	fl(i,0,n)	cin>>sal[i];
	fl(i,0,n-1){
		cin>>u>>v;
		u--,v--;
		tree[u].pb(v);
	}
	bool zero = false;
	while(q--){
		cin>>type;
		if(type==0){
			cin>>u>>m;
			u--;
			incr[u] += m;
			zero = true;
		}
		else{
			cin>>u;
			u--;
			if(zero){
				vi visited(n,0);
				dfs(tree,0,sal,visited,incr,0);
				zero = false;
				fl(i,0,n)	incr[i] = 0;
			}
			cout<<sal[u]<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}