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

int Max(Int a, Int b){
	return (a>b?a:b);
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	string s;
	cin>>s;
	vector<vector<int> > bpos(2);	//s-e
	int bs = 0;
	fl(i,0,s.length()){
		int idx = i;
		while(s[idx]=='b'){
			bs++;
			idx++;
			if(idx==s.length())	break;
		}
		if(s[i]=='b'){
			bpos[0].pb(i);
			bpos[1].pb(idx-1);
			i = idx-1;
		}
	}
	int ans = 0;
	if(bpos[0].size()==0){
		cout<<s.length()<<endl;
		return 0;
	}
	fl(i,0,bpos[0].size()){
		int st = bpos[0][i];
		int en = bpos[1][i];
		st--, en++;
		int temp = 0;
		while(st>=0){
			if(s[st--]=='a')	temp++;
		}
		while(en<s.length()){
			if(s[en++]=='a')	temp++;
		}
		ans = Max(ans,temp+bpos[1][i]-bpos[0][i]+1);
	}
	ans = Max(ans,bs+bpos[0][0]+s.length()-1-bpos[1][bpos[1].size()-1]);
	cout<<ans<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}