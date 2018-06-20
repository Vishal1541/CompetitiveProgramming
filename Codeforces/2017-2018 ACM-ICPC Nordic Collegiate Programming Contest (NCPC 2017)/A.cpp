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
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

struct player{
	string name;
	double a,b;
};

int n;
string s;
double ai,bi;

bool cmp1(const player &p1, const player &p2) { return p1.a<p2.a; }
bool cmp2(const player &p1,const player &p2) { return p1.b<p2.b; }

int main(){
	ios;
	cout.precision(2);
	cout<<fixed;


	cin>>n;
	player p1[n],p2[n];

	fl(i,0,n){
		cin>>s>>ai>>bi;
		p1[i].name = p2[i].name = s;
		p1[i].a = p2[i].a = ai;
		p1[i].b = p2[i].b = bi;
	}
	sort(p1,p1+n,cmp1);
	sort(p2,p2+n,cmp2);

	double ans = 99999999, onee,twoo,three,fourr;
	string one;
	vector<string> anss(4);
	fl(i,0,n){
		one = p1[i].name;
		onee = p1[i].a;
		// cout<<one;
		string aa[4];
		if(p2[0].name.compare(one)==0){
			twoo = p2[1].b;
			three = p2[2].b;
			fourr = p2[3].b;
			aa[1] = p2[1].name;
			aa[2] = p2[2].name;
			aa[3] = p2[3].name;
		}
		else if(p2[1].name.compare(one)==0){
			twoo = p2[0].b;
			three = p2[2].b;
			fourr = p2[3].b;
			aa[1] = p2[0].name;
			aa[2] = p2[2].name;
			aa[3] = p2[3].name;
		}
		else if(p2[2].name.compare(one)==0){
			twoo = p2[0].b;
			three = p2[1].b;
			fourr = p2[3].b;
			aa[1] = p2[0].name;
			aa[2] = p2[1].name;
			aa[3] = p2[3].name;
		}
		else{
			twoo = p2[0].b;
			three = p2[1].b;
			fourr = p2[2].b;
			aa[1] = p2[0].name;
			aa[2] = p2[1].name;
			aa[3] = p2[2].name;
		}
		if(onee+twoo+three+fourr<ans){
			ans = onee+twoo+three+fourr;
			anss[0] = p1[i].name;
			anss[1] = aa[1];
			anss[2] = aa[2];
			anss[3] = aa[3];
		}
	}
	cout<<ans<<endl;
	cout<<anss[0]<<endl<<anss[1]<<endl<<anss[2]<<endl<<anss[3]<<endl;
	// cout<<anss[2];

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}