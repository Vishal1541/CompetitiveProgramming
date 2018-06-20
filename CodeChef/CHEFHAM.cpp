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

Int nextPowerOf2(Int n)
{
  Int count = 0;
 
  /* First n in the below condition is for the case where n is 0*/
  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}

Int raiseToPow(Int x, Int power)
{
    Int result;
    Int i;
    result =1;
    for (i=1; i<=power;i++)
    {
        result = result*x;
    }
    return(result);
}

Int powerMod(Int x, Int y, Int p)
{
    Int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

int t,n;



int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

  cin>>t;
  while(t--){
    cin>>n;
    vi arr(n),idxD,idxS;
    mii m,sing;
    mii :: iterator itr;
    fl(i,0,n){
      cin>>arr[i];
      m[arr[i]]++;
    }
    if(n==1){
      cout<<0<<endl<<arr[0]<<endl;
      continue;
    }
    foreach(itr,m){
      if(itr->S==1) sing[itr->F] = 1;
    }
    fl(i,0,n){
      if(sing[arr[i]])  idxS.pb(i);
      else idxD.pb(i);
    }
    vi ans(n);
    fl(i,0,idxS.size()){
      ans[idxS[(i+1)%idxS.size()]] = arr[idxS[i]];
    }
    fl(i,0,idxD.size()){
      ans[idxD[(i+1)%idxD.size()]] = arr[idxD[i]];
    }
    cout<<n<<endl;
    fl(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
  }

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}
