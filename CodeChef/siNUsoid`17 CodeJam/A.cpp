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

int t,n;
Int X,M;

struct data{
	Int day,run,sum;
};

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>t;
	while(t--){
		cin>>n;
		data arr[n];
		Int s = 0,inp;
		mii sd;
		set<Int> store;
		set<Int> :: iterator itr;
		fl(i,0,n){
			cin>>inp;
			arr[i].day = i+1;
			arr[i].run = inp;
			s += inp;
			arr[i].sum = s;
			if(sd.find(s)==sd.end()){
				sd[s] = i+1;
				store.insert(s);
			}
		}
		cin>>M;
		Int f = M%s;
		if(f==0)	f = s;
		Int day = n+5,temp = 0;
		if(M==0){
			cout<<"0\n";
			continue;
		}
		fl(i,0,n){
			if(f-arr[i].run<=0)	day = min(day,i+1);
			else{
				Int lower = (f-arr[i].run+arr[i].sum);
				lower %= s;
				if(lower==0)	lower = s;
				itr = store.lower_bound(lower);
				day = min(day,sd[*itr]);
			}
		}
		cout<<day<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}