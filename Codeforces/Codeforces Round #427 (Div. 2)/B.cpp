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

Int k,summ = 0,diff,ans = 0;
vi counter(10,0);
string s;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>k>>s;
	fl(i,0,s.length()){
		summ += s[i]-'0';
		counter[s[i]-'0']++;
	}
	if(summ>=k){
		cout<<"0\n";
		return 0;
	}
	diff = k-summ;
	int ptr = 0;
	while(diff>0){
		if(counter[ptr]*(9-ptr)>=diff){
			ans += ceil((double)diff/(9-ptr));
			break;
		}
		ans += counter[ptr];
		diff -= counter[ptr]*(9-ptr);
		ptr++;
	}
	cout<<ans<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}