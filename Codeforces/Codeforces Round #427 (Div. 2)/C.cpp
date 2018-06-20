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
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int n,q,c,x,y,s;
Int t,x1,Y1,x2,y2;
map< pair<int,int> , vector<int> > store;
map< pair<int,int> , vector<int> > :: iterator itr;
map< pair<int,int> , Int > dp_store[15];

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>n>>q>>c;
	fl(i,0,n){
		cin>>x>>y>>s;
		store[make_pair(x,y)].pb(s);
	}
	int dp[c+1][120][120];	//t,x,y
	Int brightness[15][120][120]; //t,x,y
	fl(i,0,c+1){
		foreach(itr,store){
			pair<int,int> pxy = itr->F;
			int ins = 0;
			fl(j,0,itr->S.size()){
				ins += (store[pxy][j]+i)%(c+1);
			}
			dp_store[i][pxy] = ins;
		}
	}
	fl(cc,0,c+1)	fl(i,0,102)	brightness[cc][0][i] = 0;
	fl(cc,0,c+1)	fl(i,0,102)	brightness[cc][i][0] = 0;
	fl(cc,0,c+1){
		fl(i,1,101){
			fl(j,1,101){
				if(dp_store[cc].find(make_pair(i,j))==dp_store[cc].end()){
					brightness[cc][i][j] = brightness[cc][i][j-1];
				}
				else{
					brightness[cc][i][j] = brightness[cc][i][j-1] + dp_store[cc][make_pair(i,j)];
				}
			}
		}
	}
	while(q--){
		cin>>t>>x1>>Y1>>x2>>y2;
		t %= (c+1);
		Int ans = 0;
		fl(i,x1,x2+1){
			ans += brightness[t][i][y2]-brightness[t][i][Y1-1];
		}
		cout<<ans<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}