//    VISHAL ANAND
#include <bits/stdc++.h>

using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define us unordered_set
#define um unordered_map
#define mii map<Int,Int>
#define qi queue<Int>
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define PI 3.141592653589793238L
#define F first
#define S second
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define mp make_pair
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int getSign(char a){
	if(a=='^')	return 1;
	if(a=='>')	return 2;
	if(a=='v')	return 3;
	return 4;
}

bool checkEquality(int a, Int n){
	double x = (n-a)/4.0;
	return (x==(int)x && x>=0)?true:false;
}

int main(){
	ios;
	char s,e;
	Int n;
	cin>>s>>e>>n;
	int signS,signE,signDeltaCW,signDeltaCCW;
	bool isCW, isCCW;
	signS = getSign(s);
	signE = getSign(e);
	signDeltaCW = signE - signS;
	signDeltaCCW = signS - signE;
	while(signDeltaCW<0)	signDeltaCW += 4;
	while(signDeltaCCW<0)	signDeltaCCW += 4;
	isCW = checkEquality(signDeltaCW,n);
	isCCW = checkEquality(signDeltaCCW,n);
	if(isCW && isCCW)	cout<<"undefined\n";
	else if(isCW)	cout<<"cw\n";
	else 	cout<<"ccw\n";

	return 0;
}