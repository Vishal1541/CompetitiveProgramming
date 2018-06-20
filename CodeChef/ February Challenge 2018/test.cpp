//VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TC int t;scanf("%d",&t);while (t-->0)
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
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
Int MOD = 1000000007;
 
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}
 
Int min(Int a, Int b){return (a<b?a:b);}
Int max(Int a, Int b){return (a>b?a:b);}
Int min3(Int a, Int b, Int c){return min(a,min(b,c));}
Int max3(Int a, Int b, Int c){return max(a,max(b,c));}
Int nextPowerOf2(Int n);
Int raiseToPow(Int x, Int power);
Int powerMod(Int x, Int y, Int p);
void primeFactors(Int n);
bool isPowerOfTwo (Int x);
void allFactors(Int n);
 
const int MAX = 1009;
int t,n,comArr[MAX][MAX];
bool prime[MAX] = {1}; 
 
int commonDiv(int a, int b){
    int n = gcd(max(a,b),min(a,b)), res = 0;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            if(n/i==i)  res++;
            else    res += 2;
        }
    }
    return res;
}
 
int main(){
    fl(i,1,1001){
        fl(j,i+1,1001){
            comArr[i][j] = comArr[j][i] = commonDiv(i,j);
        }
        comArr[i][i] = 0;
    }
    fl(i,2,MAX){
        if(prime[i]){
            for(int j=2*i; j<MAX; j+=i) prime[j] = 0;
        }
    }
    prime[1] = 0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int tcase[n+1][30], arr[n+1][30], ans[n+1], inp[n+1][n+1];
        fl(i,0,n+1)  fl(j,0,30) tcase[i][j] = arr[i][j] = 0;
        vector<int> availableIp(n+1,1),availableOrig(n+1,1);
        fl(i,1,n+1){
            fl(j,1,n+1){
                tcase[i][comArr[i][j]]++;
                scanf("%d",&inp[i][j]);
                arr[i][inp[i][j]]++;
            }
        }
        for(int I=1; I<=n; I++){
            if(prime[I]){
                int idx;
                for(int i=1; i<=n; i++){
                    if(!availableIp[i]) continue;
                    bool found = 1;
                    for(int j=1; j<=28; j++){
                        if(tcase[I][j]!=arr[i][j]){
                            found = 0;
                            break;
                        }
                    }
                    if(!found)  continue;
                    ans[i] = I;
                    idx = i;
                    availableIp[i] = 0;
                    break;
                }
                for(int i=1; i<=n; i++){
                        tcase[i][comArr[i][I]]--;
                        arr[i][inp[i][idx]]--;
                    
                }
            }
        }
        for(int I=1; I<=n; I++){
            if(!prime[I]){
                int idx;
                for(int i=1; i<=n; i++){
                    if(!availableIp[i]) continue;
                    bool found = 1;
                    for(int j=1; j<=28; j++){
                        if(tcase[I][j]!=arr[i][j]){
                            found = 0;
                            break;
                        }
                    }
                    if(!found)  continue;
                    ans[i] = I;
                    idx = i;
                    availableIp[i] = 0;
                    break;
                }
                for(int i=1; i<=n; i++){
                        tcase[i][comArr[i][I]]--;
                        arr[i][inp[i][idx]]--;
                    
                }
            }
        }
        fl(i,1,n+1) availableIp[i] = 0;
        for(int i=1; i<=n; i++){
            if(ans[i])  availableIp[ans[i]] = 1;
        }
        si s;
        for(int i=1; i<=n; i++){
            if(!availableIp[i]) s.insert(i);
        }
        for(int i=1; i<=n; i++){
            if(ans[i]==0){
                ans[i] = *s.begin();
                s.erase(s.begin());
            }
        }
        fl(i,1,n+1) printf("%d\n", ans[i]);
    }
 
 
#ifndef LOCAL_DEFINE
cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
#endif
 
return 0;
}
 
void printDivisors(Int n)
{
    // Note that this loop runs till square root
    for (Int i=1; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                printf("%d ", i);
 
            else // Otherwise print both
                printf("%d %d ", i, n/i);
        }
    }
}
 
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
 
bool isPowerOfTwo (Int x)
{
  /* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1)));
}
 
// A function to print all prime factors of a given number n
void primeFactors(Int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        printf ("%d ", n);
}   