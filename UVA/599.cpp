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

Int t;
string str;

void dfs(vvi& tree, Int node, vi& visited, Int& nodesCount){
	visited[node] = 1;
	nodesCount++;
	fl(i,0,tree[node].size()){
		if(!visited[tree[node][i]])
			dfs(tree, tree[node][i], visited, nodesCount);
	}
}

int main(){
	ios;
	cin>>t;
	while(t--){
		vvi tree(30);
		vi visited(26,0),flag(26,0);
		Int treeCount = 0, acorsCount = 0, nodesCount;
		cin>>str;
		while(str[0]!='*'){
			tree[str[1]-'A'].pb(str[3]-'A');
			tree[str[3]-'A'].pb(str[1]-'A');
			cin>>str;
		}
		cin>>str;
		for(int i=0; i<str.length(); i+=2)	flag[str[i]-'A'] = 1;
		fl(i,0,26){
			nodesCount = 0;
			if(flag[i]==1 && !visited[i])
				dfs(tree, i, visited, nodesCount);
			if(nodesCount==1)	acorsCount++;
			else if(nodesCount>1)	treeCount++;
		}
		cout<<"There are "<<treeCount<<" tree(s) and "<<acorsCount<<" acorn(s).\n";
	}	

	return 0;
}