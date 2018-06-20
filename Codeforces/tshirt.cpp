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

struct type{
	int p,a,b;
};

int n,p,a,b,m,inp;
si one,two,three;
si_it itr;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>n;
	type store[n];
	fl(i,0,n)	cin>>store[i].p;
	fl(i,0,n)	cin>>store[i].a;
	fl(i,0,n)	cin>>store[i].b;
	fl(i,0,n){
		if(store[i].a==1 || store[i].b==1)	one.insert(store[i].p);
		if(store[i].a==2 || store[i].b==2)	two.insert(store[i].p);
		if(store[i].a==3 || store[i].b==3)	three.insert(store[i].p);
	}
	cin>>m;
	while(m--){
		cin>>inp;
		if(inp==1){
			if(!one.empty()){
				int aa = *one.begin();
				cout<<aa<<" ";
				one.erase(aa);
				two.erase(aa);
				three.erase(aa);
			}
			else
				cout<<"-1 ";
		}
		else if(inp==2){
			if(!two.empty()){
				int aa = *two.begin();
				cout<<aa<<" ";
				one.erase(aa);
				two.erase(aa);
				three.erase(aa);
			}
			else
				cout<<"-1 ";
		}
		else if(inp==3){
			if(!three.empty()){
				int aa = *three.begin();
				cout<<aa<<" ";
				one.erase(aa);
				two.erase(aa);
				three.erase(aa);			}
			else
				cout<<"-1 ";
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}