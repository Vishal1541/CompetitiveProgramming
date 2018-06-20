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
void primeFactors(Int n);
bool isPowerOfTwo (Int x);
void allFactors(Int n);

int t,n,m,dp[5009][5009], L[5009][5009];
string s1,s2,temp1,temp2;

int lcs( string X, string Y, int m, int n )
{
   // int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

    cin>>t;
    while(t--){
        cin>>n>>m>>temp1>>temp2;
        s1 = "";
        s2 = "";
        s1 += temp1[0], s2 += temp2[0];
        int idx = 0;
        for(int i=1; i<n; i++){
            if(temp1[i]!=s1[idx]){
                s1 += temp1[i];
                idx++;
            }
        }
        idx = 0;
        for(int i=1; i<m; i++){
            if(temp2[i]!=s2[idx]){
                s2 += temp2[i];
                idx++;
            }
        }
        n = s1.length();
        m = s2.length();

        cout<<(m+n-lcs(s1,s2,n,m))<<endl;

        // dp[0][0] = (s1[0]==s2[0]?m:m+1);
        // // cout<<s1<<"__"<<s2;
        // for(int i=1; i<n; i++){
        //     dp[i][0] = (s1[i]==s2[0]?dp[i-1][0]:dp[i-1][0]
        //                     + (s1[i-1]==s2[0]?2:1));
        // }
        // for(int j=1; j<m; j++){
        //     if(s1[0]==s2[j-1] || s1[0]==s2[j])    dp[0][j] = m;
        //     else    dp[0][j] = m+1;
        // }
        // dp[0][m] = (s1[0]==s2[m-1]?m:m+1);
        // int mm;
        // for(int i=1; i<n; i++){
        //     mm = dp[i-1][0];
        //     for(int j=1; j<=m; j++){
        //         dp[i][j] = min(mm+(s1[i]==s2[j-1] || s1[i]==s2[j]?0:1),dp[i-1][j]+1);
        //         mm = min(mm,dp[i-1][j]);
        //     }
        // }
        // fl(i,0,n){
        //     fl(j,0,m+1) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<dp[n-1][m]<<endl;
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