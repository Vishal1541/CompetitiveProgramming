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

int t;
string s;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>t;
	while(t--){
		cin>>s;
		int r=0,l=0;
		bool loop = false;
		fl(i,0,s.length()){
			loop = false;
			while(s[i]=='R'){
				loop = true;
				i++;
				if(i==s.length())	break;
			}
			if(loop)
				r++;
		}	
		fl(i,0,s.length()){
			loop = false;
			while(s[i]=='L'){
				loop = true;
				i++;
				if(i==s.length())	break;
			}
			if(loop)
				l++;
		}	
		cout<<min(l,r)<<endl;
	}


	return 0;
}