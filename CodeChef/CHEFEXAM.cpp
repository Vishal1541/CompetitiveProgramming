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
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int N,M,a,b,c,t,total=0,req=0,hr=0,idx=0;

struct marks{
	int A,B,C,t;
};

bool cmp(const marks&a, const marks&b){return (a.C>b.C);}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>N>>M;
	marks arr[N];
	fl(i,0,N){
		cin>>arr[i].A>>arr[i].B>>arr[i].C;
		arr[i].t = (arr[i].B-arr[i].A)/arr[i].C;
		total += arr[i].A;
	}
	sort(arr,arr+N,cmp);
	req = M*N-total;
	while(req>0){
		if(idx==N)	break;
		if(arr[idx].t>0){
			arr[idx].t--, hr++;
			req -= arr[idx].C;
		}
		else idx++;
	}
	cout<<(req>0?-1:hr)<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}