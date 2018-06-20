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
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int n,L;

int main(){
	ios;
	cin>>n>>L;
	vi pl1(n),pl2(n),arr1(n),arr2(n);
	fl(i,0,n)	cin>>pl1[i];
	fl(i,0,n)	cin>>pl2[i];
	fl(i,1,n){
		arr1[i-1]=pl1[i]-pl1[i-1];
		arr2[i-1]=pl2[i]-pl2[i-1];
	}
	arr1[n-1]=pl1[0]-pl1[n-1]+L;
	arr2[n-1]=pl2[0]-pl2[n-1]+L;
	bool yes=false,oper;
	fl(nxt,0,n){
		oper=false;
		fl(i,0,n){
			if(arr1[i]!=arr2[i]){
				Int val=arr1[n-1];
				arr1.pop_back();
				arr1.insert(arr1.begin(),val);
				oper=true;
				break;
			}
			if(i==n-1){
				yes=true;
				break;
			}
		}
		if(yes)	break;
	}

	if(yes)	cout<<"YES\n";
	else	cout<<"NO\n";

	return 0;
}