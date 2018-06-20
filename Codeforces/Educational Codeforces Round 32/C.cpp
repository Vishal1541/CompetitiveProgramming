//    VISHAL ANAND
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

Int min(Int a,Int b){
	return (a<b?a:b);
}
Int max(Int a,Int b){
	return (a>b?a:b);
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	string s;
	cin>>s;
	int len = s.length(), ans = 100009,temp;
	vvi alpha(26);
	fl(i,0,len){
		alpha[s[i]-'a'].pb(i);
	}
	fl(i,0,26){
		if(alpha[i].size()){
			alpha[i].pb(-1);
			alpha[i].pb(len);
			sort(alpha[i]);
		}
	}
	fl(i,0,26){
		if(alpha[i].size()){
			temp = -1;
			fl(j,1,alpha[i].size()){
				temp = max(temp,alpha[i][j]-alpha[i][j-1]);
			}
			ans = min(ans,temp);
		}
	}
	cout<<ans<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}