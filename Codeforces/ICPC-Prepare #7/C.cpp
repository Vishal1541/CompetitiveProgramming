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

Int n;
vi cost(100009,0);

struct lexico{
	string orig,rev;
	Int c_orig, c_rev;
};
lexico arr[100009];

void reverseStr(string &str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i=0; i<n/2; i++)
       swap(str[i], str[n-i-1]);
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n;
	fl(i,0,n)	cin>>cost[i];
	fl(i,0,n){
		cin>>arr[i].orig;
		arr[i].rev = arr[i].orig;
		reverseStr(arr[i].rev);
	}
	arr[0].c_orig = 0;
	arr[0].c_rev = cost[0];
	fl(i,1,n){
		arr[i].c_orig = arr[i].c_rev = 999999999999999;
		if(arr[i].orig.compare(arr[i-1].orig)>=0){
			arr[i].c_orig = min(arr[i].c_orig,arr[i-1].c_orig);
		}
		if(arr[i].orig.compare(arr[i-1].rev)>=0){
			arr[i].c_orig = min(arr[i].c_orig,arr[i-1].c_rev);
		}
		if(arr[i].rev.compare(arr[i-1].orig)>=0){
			arr[i].c_rev = min(arr[i].c_rev,cost[i]+arr[i-1].c_orig);
		}
		if(arr[i].rev.compare(arr[i-1].rev)>=0){
			arr[i].c_rev = min(arr[i].c_rev,cost[i]+arr[i-1].c_rev);
		}
	}
	Int ans = min(arr[n-1].c_orig,arr[n-1].c_rev);
	if(ans==999999999999999){cout<<"-1\n";}
	else{cout<<ans<<endl;}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}