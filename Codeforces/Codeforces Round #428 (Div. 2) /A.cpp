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

Int n,k;

int main(){
	ios;
	cin>>n>>k;
	int arr[n];
	fl(i,0,n)	cin>>arr[i];
	Int saved=0,given=0,days=0;
	fl(i,0,n){
		days++;
		if(arr[i]>8){
			given += 8;
			saved += arr[i]-8;
		}
		else{
			if((arr[i]+saved)>8){
				given += 8;
				saved -= (8-arr[i]);
			}
			else{
				given += arr[i]+saved;
				saved=0;
			}
		}
		if(given>=k)	break;
	}
	if(given>=k)	cout<<days<<endl;
	else 	cout<<"-1\n";

	return 0;
}