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

string s1,s2,s3,s4;
int l1,l2,l3,l4;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>s1>>s2>>s3>>s4;
	l1 = s1.length()-2;
	l2 = s2.length()-2;
	l3 = s3.length()-2;
	l4 = s4.length()-2;
	if(l1>=l2*2 && l1>=l3*2 && l1>=l4*2)	cout<<"A";
	else if(2*l1<=l2 && 2*l1<=l3 && 2*l1<=l4) cout<<"A";

	else if(l2>=l1*2 && l2>=l3*2 && l2>=l4*2)	cout<<"B";
	else if(2*l2<=l1 && 2*l2<=l3 && 2*l2<=l4) cout<<"B";

	else if(l3>=l1*2 && l3>=l2*2 && l3>=l4*2)	cout<<"C";
	else if(2*l3<=l1 && 2*l3<=l2 && 2*l3<=l4) cout<<"C";

	else if(l4>=l1*2 && l4>=l3*2 && l4>=l1*2)	cout<<"D";
	else if(2*l4<=l1 && 2*l4<=l3 && 2*l4<=l1) cout<<"D";

	else 	cout<<"C";

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}