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
// #define sort(v) sort(v.begin(),v.end());
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
bool cmp(const double& a, const double& b){
  return a>b;
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

  int n;
  cin>>n;
  string s[n];
  fl(i,0,n) cin>>s[i];
  int ans = 99999999;
  bool found = true;
  fl(i,0,n){
    int moves = 0;
    fl(j,0,n){
      if(i!=j){
        int idxi = 0, idxj = 0, prv = 1;
        while(idxi<s[0].length()){
          if(s[i][idxi]==s[j][idxj%s[0].length()]){
            idxj++;
            idxi++;
            continue;
          }
          idxj = prv;
          if(idxj==s[0].length()){
            found = false;
            break;
          }
          idxi = 0;
          prv++;
        }
        if(!found)  break;
        moves += prv-1;
      }
      if(!found)  break;
    }
    if(!found) break;
    ans = min(ans,moves);
  }
  cout<<(found?ans:-1);  

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}