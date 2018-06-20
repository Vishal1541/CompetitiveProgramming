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

Int n,u,v,curr_color=1,b=0,f=0,popped;
vi colors(100009,0),flag(100009,0),q(100009,-1);

void change(){
	if(curr_color==1)	curr_color = 2;
	else 	curr_color = 1;
}

int main(){
	ios;
	cin>>n;
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	vvi tree(n+2);
	vi visited(n+2,0);
	fl(i,0,n-1){
		cin>>u>>v;
		u--,v--;
		tree[u].pb(v);
		tree[v].pb(u);
	}
		colors[0] = curr_color;
		visited[0] = 1;
		change();
		q[f++] = 0;
		// fl(j,0,tree[i].size()){
		// 	colors[tree[i][j]] = curr_color;
		// 	q[f++] = tree[i][j];
		// }
		while(b<f){
			popped = q[b++];
			curr_color = colors[popped];
			change();
			fl(j,0,tree[popped].size()){
				if(!visited[tree[popped][j]]){
					q[f++] = tree[popped][j];
					visited[tree[popped][j]] = 1;
					colors[tree[popped][j]] = curr_color;
				}
			}
		}
		 // fl(i,0,n)	cout<<colors[i]<<" ";
		Int ones=0,twos=0,ans=0;
		fl(i,0,n){
			if(colors[i]==1)	ones++;
			else if(colors[i]==2)	twos++;
		}
		// cout<<ones<<twos<<" ..";
		fl(i,0,n){
			curr_color = colors[i];
			if(curr_color==1){
				ans += twos - tree[i].size();
			}
		}
		cout<<ans<<endl;

	return 0;
}