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

Int t,m,c,mem[22][205],price[22][22],ans;

Int solve(Int g, Int money){
	if(money<0)	return -999;
	if(g==c)	return m-money;
	Int a=-1;
	if(mem[g][money]!=-1)	return mem[g][money];
	fl(i,1,price[g][0]+1){
		a = max(a,solve(g+1, money-price[g][i]));
	}
	return mem[g][money]=a;
}

int main(){
	ios;
	cin>>t;
	while(t--){
		cin>>m>>c;
		memset(mem,-1,sizeof(mem));
		fl(i,0,c){
			cin>>price[i][0];
			fl(j,1,price[i][0]+1){
				cin>>price[i][j];
			}
		}
		ans = solve(0,m);
		if(ans==-1)	cout<<"no solution\n";
		else 	cout<<ans<<endl;
	}

	return 0;
}