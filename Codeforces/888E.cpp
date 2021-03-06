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

int n,m,ans=0,power;
vector<int> subsets1(500000),subsets2(500000);
set<int> lasthalf;
set<int> :: iterator itr;

int raiseToPow(int x, int power)
{
    int result;
    int i;
    result =1.0;
    for (i=1; i<=power;i++)
    {
        result = result*x;
    }
    return(result);
}

void makeSubsets(vector<int>& arr, vector<int> &subsets,int l, int h){
     int idx = 0;
     power = raiseToPow(2,n/2);
     fl(i,l,h){
          subsets[idx++] = arr[i]%m;
          int u = idx-1;
          fl(j,0,u)
               subsets[idx++] = (subsets[j]+arr[i])%m;
     }
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	
	cin>>n>>m;
	vector<int> arr(n);
	fl(i,0,n) cin>>arr[i];
	makeSubsets(arr,subsets1,0,n/2);
	makeSubsets(arr,subsets2,n/2,n);
	fl(i,0,power)  lasthalf.insert((subsets2[i]%m)*(-1));
	fl(i,0,power-1){
	     ans =  max(ans,subsets1[i]);
	     itr = lasthalf.lower_bound(m-subsets1[i]-1);
	     if(*itr)  ans = max(ans,max(*itr*(-1),(ans+*itr*(-1))%m));
	     itr = lasthalf.lower_bound(2*m-subsets1[i]-1);
	     if(*itr)  ans = max(ans,max(*itr*(-1),(ans+*itr*(-1))%m));
	     ans = max(ans,(-1)*(*lasthalf.begin()));
	}
	cout<<ans<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}
