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

int n,x,y,ans = 0,it = 1;
vector<pair<int,int> > arr(1009);

int findDir(int a, int b){
     if(arr[a].F == arr[b].F){
          if(arr[b].S>arr[a].S)    return 1;
          return 3;
     }
     if(arr[b].F>arr[a].F)    return 2;
     return 4;
}

void check(int a, int b, int c){   
     int dir1 = findDir(a,b);
     int dir2 = findDir(b,c);
     if((dir1==1 && dir2==4) || (dir1==3 && dir2==2) || (dir1==4 && dir2==3) || (dir1==2 && dir2==1)){
          ans++;
     }
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

     cin>>n;
     fl(i,0,n+1){
          cin>>x>>y;
          arr[i].F = x;
          arr[i].S = y;
     }
     fl(i,0,n-1){
          check(i,i+1,i+2);
     }
     check(n-1,n,1);
     cout<<ans<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}
