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
bool primeFactors(Int n);
bool isPowerOfTwo (Int x);
void allFactors(Int n);

int n;
mii m;
vi primes2, ans(56505464+9,0);
mii flag;

void solve(Int num, int idx, int times){
    if(num>=26505469)   return;
    if(times>1)
        ans[num] = 1;
    fl(i,idx,1654128){
        if(num*primes2[i]>=26505469)    return;
        if(times==1 && i!=idx)
            solve(num*primes2[i],i,1);
        else
            solve(num*primes2[i],i,2);
    }
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
    cin>>n;
    // for(int i=2; i<=26505469; i++){
    //     if(!flag[i]){
    //         flag[i] = 1;
    //         primes2.pb(i);
    //         for(int j=2*i; j<=26505469; j+=i){
    //             flag[j] = 1;
    //         }
    //     }
    // }
    // fl(i,0,1654128){
    //     if(primes2[i]*primes2[i]>=26505469) break;
    //     solve(primes2[i],i,1);
    // }

    for(Int i=2; i<=10000000; i++){
        if(!flag[i]){
            Int sq = i*i;
            flag[sq] = 1;
            for(Int j = 25505465; j<=400000000000000; j+=sq){
                ans[j-25505465] = 1;
                flag[j - 25505465] = 1;
            }
        }
    }

    int cnt = 0;
    fl(i,0,56505369){
        if(ans[i]){
            cnt++;
            if(cnt==n-10000000){
                cout<<i+25505464<<" ";
                return 0;
            }
        }
    }
	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
    // 26505469
    // 10^7 th --> 25505464
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
bool primeFactors(Int n)
{
    // Print the number of 2s that divide n
    Int times = 0;
    while (n%2 == 0)
    {
        times++;
        n = n/2;
        if(flag[n] || times>1) return 1;
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (Int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        times = 0;
        if(flag[n]) return 1;
        while (n%i == 0)
        {
            times++;
            n = n/i;
            if(flag[n] || times>1) return 1;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    return 0;
    if (n > 2)
        printf ("%d ", n);
}