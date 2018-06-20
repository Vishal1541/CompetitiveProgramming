//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int int
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

vi arr(15000000,0);
vi primeno;
int n;

int main(){


	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n;

	fl(i,2,10467398){
		if(arr[i]==0){
			for(int j=2*i; j<=10467398; j+=i){
				arr[j] = 1;
			}
		}
	}
	fl(i,2,10467398){
		if(arr[i]==0)	primeno.pb(i);
	}
	bool yes = true;
	Int counter = 0;
	int temp;
	fl(i,0,primeno.size()){
		if(n%primeno[i]==0){
			counter++;
			temp = 	n/primeno[i];
			if(temp%primeno[i]==0){
				yes = false;
				break;
			}
			if(counter>3){
				yes = false;
				break;
			}
		}
	}
	cout<<((yes && counter==3)?"YES\n":"NO\n");

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}