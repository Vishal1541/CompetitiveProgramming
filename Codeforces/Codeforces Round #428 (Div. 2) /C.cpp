//    VISHAL ANAND
#include <bits/stdc++.h>

using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
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

Int n;
vi dist_arr,prob;

void dfs(vvi &arr, vi &visited, Int city, Int dist, Int probablity){
	Int pr=0;
	visited[city]=1;
	bool loop=false;
	fl(i,0,arr[city].size()){
		if(!visited[arr[city][i]])		pr++;
	}
	if(pr==0)	pr = 1;
	fl(i,0,arr[city].size()){
		if(!visited[arr[city][i]]){
			loop=true;
			dfs(arr,visited,arr[city][i],dist+1,pr*probablity);
		}
	}
	if(!loop){
		dist_arr.pb(dist);
		prob.pb(pr*probablity);
	}
}

int main(){
	ios;
	cout.precision(20);
	cin>>n;
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	vvi arr(n);
	vi visited(n,0);
	fl(i,0,n-1){
		Int c1,c2;
		cin>>c1>>c2;
		c1--,c2--;
		arr[c1].pb(c2);
		arr[c2].pb(c1);
	}
	//dfs_check_prob(arr,visited_temp,0,1);
	dfs(arr,visited,0,0,1);
	long double div=dist_arr.size(),ans=0;
	fl(i,0,div)	ans += ((long double)dist_arr[i]/(long double)prob[i]);
	cout<<fixed<<ans<<endl;

	return 0;
}