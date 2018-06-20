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

Int n,inp,chance=2,bob=0,alice=0;
bool passed;

void playOpt(vi& arr, Int idx, Int& b, Int& a,Int chance){
	Int B,A;
	if(chance==2){
		if(idx==n){
			// b += arr[n-1];
			return;
		}
		B = b+arr[idx];
		A = a+arr[idx];
		playOpt(arr,idx+1,B,a,1);
		playOpt(arr,idx+1,b,A,2);
		b = max(b,B);
	}
	else{
		if(idx==n){
			// a += arr[n-1];
			return;
		}
		B = b+arr[idx];
		A = a+arr[idx];
		playOpt(arr,idx+1,B,a,1);
		playOpt(arr,idx+1,b,A,2);
		a = max(a,A);	
	}
}

Int playOptAlice(vi& arr, Int idx,bool& pass){

}

int main(){
	ios;
	cin>>n;
	vi arr(n);
	fl(i,0,n)	cin>>arr[i];
	playOpt(arr,0,bob,alice,2);
	cout<<alice<<" "<<bob<<endl;

	return 0;
}