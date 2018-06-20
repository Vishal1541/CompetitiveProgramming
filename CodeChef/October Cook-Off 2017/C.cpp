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

int t;
string s;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>t;
	while(t--){
		cin>>s;
		if(s.length()==1)	cout<<"0\n";
		else if(s.length()==2){
			if(s[0]==s[1])	cout<<"1\n";
			else 	cout<<"0\n";
		}
		else{
			int b=0, f=2, ans=0;
			set<char> flag_alpha;
			vi count_alpha(200,0);
			count_alpha[s[1]]++;
			flag_alpha.insert(s[1]);
			fl(i,1,s.length())	if(s[i]==s[i-1])	ans++;
			while(f<s.length()){
				if(flag_alpha.size()==0){
					count_alpha[s[f]]++;
					flag_alpha.insert(s[f]);
					f++;
					continue;
				}
				if(flag_alpha.size()==1){
					if(s[b]==s[f]){
						ans++;
					}
						count_alpha[s[f]]++;
						flag_alpha.insert(s[f]);
						f++;
				}
				else{
					b++;
					count_alpha[s[b]]--;
					if(count_alpha[s[b]]==0)	flag_alpha.erase(s[b]);
				}
			}
			count_alpha[s[f-1]]--;
			if(count_alpha[s[f-1]]==0)	flag_alpha.erase(s[f-1]);
			count_alpha[s[b+1]]--;
			if(count_alpha[s[b+1]]==0)	flag_alpha.erase(s[b+1]);
			fl(i,b+1,f-2){
				if(s[i]==s[f-1] && flag_alpha.size()==1)
					ans += count_alpha[s[i]];
				count_alpha[s[i+1]]--;
				if(count_alpha[s[i+1]]==0)	flag_alpha.erase(s[i+1]);
			}
			cout<<ans<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}