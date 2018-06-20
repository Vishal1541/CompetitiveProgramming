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

Int T,N;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>T;
	while(T--){
		cin>>N;
		Int N_ = N;
		string s;
		vi flag(500,0);
		Int counter = 0;
		if(N==0){
			cout<<"INSOMNIA\n";
			continue;
		}
		while(counter!=10){
			s = to_string(N_);
			fl(i,0,s.length()){
				if(flag[s[i]]==0){
					flag[s[i]] = 1;
					counter++;
				}
			}
			if(counter==10)	break;
			N_ = N + N_;
		}
		cout<<N_<<endl;
	}

	return 0;
}