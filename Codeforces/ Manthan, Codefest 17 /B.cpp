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

int max(int a, int b){
	return (a>b?a:b);
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	Int n,p,q,r,ans = -4446744073709551610;
	cin>>n>>p>>q>>r;
	vi arr(n);
	fl(i,0,n)	cin>>arr[i];
	// sort(arr);
	Int arr1[5][n], arr2[5][n], arr3[5][n];

	fl(i,0,n){
		arr1[0][i] = arr[i]*p;
		arr2[0][i] = arr[i]*q;
		arr3[0][i] = arr[i]*r;
	}
	Int m1 = arr1[0][0], m2 = arr2[0][n-1], m2_ = arr2[0][0], m3_ = arr3[0][0], m3 = arr3[0][n-1];
	Int idx, idx2, idx2_, idx3_, idx3;

	fl(i,0,n){
		if(arr1[0][i]>=m1){
			m1 = arr1[0][i];
			idx = i;
		}
		arr1[1][i] = m1;
		arr1[2][i] = idx;


		if(arr2[0][i]>=m2_){
			m2_ = arr2[0][i];
			idx2_ = i;
		}
		arr2[3][i] = m2_;
		arr2[4][i] = idx2_;


		if(arr2[0][n-i-1]>=m2){
			m2 = arr2[0][n-i-1];
			idx2 = n-i-1;
		}
		arr2[1][n-i-1] = m2;
		arr2[2][n-i-1] = idx2;

		if(arr3[0][i]>=m3_){
			m3_ = arr3[0][i];
			idx3_ = i;
		}
		arr3[3][i] = m3_;
		arr3[4][i] = idx3_;

		if(arr3[0][n-i-1]>=m3){
			m3 = arr3[0][n-i-1];
			idx3 = n-i-1;
		}
		arr3[1][n-i-1] = m3;
		arr3[2][n-i-1] = idx3;
	}

	fl(i,0,n){
		ans = max(ans, arr1[1][i] + arr2[1][arr1[2][i]] + arr3[1][arr2[2][arr1[2][i]]]);
	}
	for(int i=n-1; i>=0; i--){
		ans = max(ans, arr3[1][i] + arr2[3][arr3[2][i]] + arr1[1][arr2[4][arr3[2][i]]] );
	}

	cout<<ans;

	return 0;
}