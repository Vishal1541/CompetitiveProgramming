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

int main(){
	ios;
	int arr[4][4];
	fl(i,0,4)	fl(j,0,4)	cin>>arr[i][j];
	bool yes = true;
	fl(i,0,4){
		if(arr[i][3]){
			if(arr[i][0] || arr[i][1] || arr[i][2]){
				yes = false;
				break;
			}
		}
	}
	if(arr[0][3]){
		if(arr[3][2] || arr[2][1] || arr[1][0])
			yes = false;
	}
	if(arr[1][3]){
		if(arr[0][2] || arr[3][1] || arr[2][0])
			yes = false;
	}
	if(arr[2][3]){
		if(arr[1][2] || arr[0][1] || arr[3][0])
			yes = false;
	}
	if(arr[3][3]){
		if(arr[2][2] || arr[1][1] || arr[0][0])
			yes = false;
	}
	cout<<(yes?"NO\n":"YES\n");

	return 0;
}