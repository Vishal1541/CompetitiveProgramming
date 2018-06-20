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

Int n,m,k,f,per;
Int arr[2][110];
bool found = false;

int main(){
	ios;
	fl(i,0,110){
		arr[0][i] = 999999;
		arr[1][i] = -1000000;
	}
	// arr[0][1] = 1;
	// arr[0][100] = arr[1][100] = 100;

	cin>>n>>m;
	while(m--){
		cin>>k>>f;
		if(k<arr[0][f])	arr[0][f] = k;
		if(k>arr[1][f])	arr[1][f] = k;
	}
	fl(i,1,102){
		if(arr[0][i+1]-arr[1][i]==1){
			per = arr[1][i]/i;
			found = true;
			break;
		}
		if(arr[0][i]==arr[1][i]==i){
			per = 1;
			break;
		}
	}
	if(found)
		cout<<ceil((double)n/per)<<endl;
	else
		cout<<"-1\n";

	return 0;
}