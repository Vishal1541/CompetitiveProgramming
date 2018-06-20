//VISHAL ANAND
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

int n,GCD,ans = 99999,ones = 0;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

     cin>>n;
     vector<int> arr(n);
     fl(i,0,n) cin>>arr[i];
     if(n==1){
          if(arr[0]==1)  cout<<"0\n";
          else      cout<<"-1\n";
          return 0;
     }
     else{
          fl(i,0,n) if(arr[i]==1)  ones++;
          if(ones){
               cout<<n-ones<<endl;
               return 0;
          }
          GCD = arr[0];
          fl(i,1,n) GCD = gcd(GCD,arr[i]);
          if(GCD != 1){
               cout<<"-1\n";
               return 0;
          }
          fl(i,0,n){
               GCD = arr[i];
               fl(j,i+1,n){
                    GCD = gcd(GCD,arr[j]);
                    if(GCD==1){
                         ans = min(ans,j-i+n-1);
                         break;
                    }
               }
          }
          cout<<ans<<endl;
     }     

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}

