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
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int t,n,a,b,c,inp,country,popu;

struct combine{
	Int C,Safety,Intake,Dist,Flag;
};

bool cmp(combine A, combine B){
	return (A.Dist < B.Dist);
}

void dfs(auto& tree, combine *arr, Int node, auto& visited, Int dis){
	visited[node] = 1;
	if(node!=country)
		arr[node].Flag = 1;
	arr[node].Dist = dis;
	fl(i,0,tree[node].size()){
		if(!visited[tree[node][i].F] && arr[tree[node][i].F].Safety>arr[country].Safety){
			dfs(tree, arr, tree[node][i].F, visited, dis+tree[node][i].S);
		}
	}
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>t;
	while(t--){
		cin>>n;
		combine arr[n];
		vector< vector< pair<Int,Int> > > tree(n);
		fl(i,0,n-1){
			cin>>a>>b>>c;
			a--,b--;
			tree[a].pb(make_pair(b,c));
			tree[b].pb(make_pair(a,c));
		}
		fl(i,0,n){
			cin>>inp;
			arr[i].C = i;
			arr[i].Flag = 0;
			arr[i].Safety = inp;
		}
		fl(i,0,n){
			cin>>inp;
			arr[i].Intake = inp;
		}
		cin>>country>>popu;
		country--;
		Int total_capa = 0;
		arr[country].Dist = 0;
		vi visited(n,0);
		dfs(tree, arr, country, visited, 0);
		fl(i,0,n){
			if(arr[i].Flag==1)	total_capa += arr[i].Intake;
		}
		if(total_capa<popu){
			cout<<"NO -1\n";
			continue;
		}
		sort(arr, arr+n, cmp);
		Int left = popu, ans = 0;
		if(left>0){
			fl(i,1,n){
				if(arr[i].Flag==1){
					left -= arr[i].Intake;
				}
				if(left<=0){
					ans = arr[i].Dist;
					break;
				}
				
			}
		}
		cout<<"YES "<<ans<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}