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

string s1,s2,s3;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>s1>>s2>>s3;
	vi flag(200,0), flag2(200,0);
	fl(i,0,s1.length())	flag[s1[i]]++;
	fl(i,0,s2.length())	flag[s2[i]]++;
	fl(i,0,s3.length())	flag2[s3[i]]++;
	bool yes = true;
	fl(i,0,200)	if(flag[i]!=flag2[i])	{yes=false;break;}
	cout<<(yes?"YES\n":"NO\n");

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}