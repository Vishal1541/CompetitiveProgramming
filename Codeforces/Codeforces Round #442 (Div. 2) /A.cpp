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

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	string s;
	cin>>s;
	string s1 = "Ann", s2="Slava", s3="Olya", s4="Danil", s5="Nikita";
	vi counter(5,0);
	fl(i,0,s.length()){
		int ptr = i;
		if(s[i]=='A'){
			if(i+2<s.length()){
				if(s[i+1]=='n' && s[i+2]=='n'){
					counter[0]++;
				}
			}
		}
		else if(s[i]=='S'){
			if(i+4<s.length()){
				if(s[i+1]=='l' && s[i+2]=='a' && s[i+3]=='v' && s[i+4]=='a'){
					counter[1]++;
				}
			}
		}
		else if(s[i]=='O'){
			if(i+3<s.length()){
				if(s[i+1]=='l' && s[i+2]=='y' && s[i+3]=='a'){
					counter[2]++;
				}
			}
		}
		else if(s[i]=='D'){
			if(i+4<s.length()){
				if(s[i+1]=='a' && s[i+2]=='n' && s[i+3]=='i' && s[i+4]=='l'){
					counter[3]++;
				}
			}
		}
		else if(s[i]=='N'){
			if(i+5<s.length()){
				if(s[i+1]=='i' && s[i+2]=='k' && s[i+3]=='i' && s[i+4]=='t' && s[i+5]=='a'){
					counter[4]++;
				}
			}
		}
	}
	if(counter[0]+counter[1]+counter[2]+counter[3]+counter[4]==1){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}