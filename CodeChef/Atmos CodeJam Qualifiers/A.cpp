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

int T,N,K;
string s1, s2;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>T;
	while(T--){
		vi flag(200,0);
		cin>>s1;
		vector<string> ans;
		fl(i,0,s1.length())	flag[s1[i]]=1;
		cin>>N>>K;
		fl(i,0,N){
			int cnt = 0;
			vi flag2(200,0);
			cin>>s2;
			fl(j,0,s2.length()){
				flag2[s2[j]] = 1;
			}
			fl(j,0,200){
				if(flag[j]==1 && flag2[j]==1){
					cnt++;
				}
			}
			if(cnt>=K)
				ans.pb(s2);
		}
		if(ans.size()==0){
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
			fl(i,0,ans.size()){
				cout<<ans[i]<<endl;
			}
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}