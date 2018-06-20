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

int ans = 0;

void dfs(auto& color,auto& graph, auto& visited, int v, int last){
	visited[v] = 1;
	if(color[v]!=last)	ans++;
	fl(i,0,graph[v].size()){
		if(!visited[graph[v][i]])	dfs(color,graph,visited,graph[v][i],color[v]);
	}
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	int n;
	cin>>n;
	vvi graph(n+1);
	vi color(n+1),visited(n+1,0);
	fl(i,1,n){
		int p;
		cin>>p;
		graph[i+1].pb(p);
		graph[p].pb(i+1);
	}
	fl(i,0,n)	cin>>color[i+1];
	dfs(color,graph,visited,1,0);
	cout<<ans;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}
