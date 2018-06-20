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

struct suffix{
    int idx;
    int R[2];
};
int cmp(struct suffix a, struct suffix b){
    return (a.R[0] == b.R[0])?
           (a.R[1] < b.R[1] ?1: 0):
           (a.R[0] < b.R[0] ?1: 0);
}
vi buildTree(string textt, int n){
    struct suffix sufArray[n];
    fl(i,0,n){
        sufArray[i].idx = i;
        sufArray[i].R[0] = textt[i] - 'a';
        sufArray[i].R[1] = ((i+1) < n)?
                              (textt[i + 1] - 'a'): -1;
    }
    sort(sufArray, sufArray+n, cmp);
 
    int ind[n]; 
 
    for (int k = 4; k < 2*n; k = k*2){
        int R = 0;
        int prev_R = sufArray[0].R[0];
        sufArray[0].R[0] = R;
        ind[sufArray[0].idx] = 0;
 
        fl(i,1,n){
            if (sufArray[i].R[0] == prev_R &&
               sufArray[i].R[1] == sufArray[i-1].R[1]){
                prev_R = sufArray[i].R[0];
                sufArray[i].R[0] = R;
            }
 
            else {
                prev_R = sufArray[i].R[0];
                sufArray[i].R[0] = ++R;
            }
            ind[sufArray[i].idx] = i;
        }
 
        for (int i = 0; i < n; i++){
            int nextindex = sufArray[i].idx + k/2;
            sufArray[i].R[1] = (nextindex < n)?
                      sufArray[ind[nextindex]].R[0]: -1;
        }
 
        sort(sufArray, sufArray+n, cmp);
    }
    vi suffixArr;
    for (int i = 0; i < n; i++)
        suffixArr.push_back(sufArray[i].idx);
 
    return  suffixArr;
}
 
vi lcpUtil(string txt, vi suffixArr){
    int n = suffixArr.size();
    vi lcp(n, 0);
    vi invSuff(n, 0);
    fl(i,0,n)
        invSuff[suffixArr[i]] = i;
    int k = 0;
 
    fl(i,0,n){
        if (invSuff[i] == n-1){
            k = 0;
            continue;
        }
        int j = suffixArr[invSuff[i]+1];
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;
        lcp[invSuff[i]] = k;
        if (k>0)
            k--;
    }
    return lcp;
}
 
int firstNsum(int N){
    return (N * (N + 1)) / 2;
}
char solve(string str, int K)
{
    int n = str.length();
    vi suffixArr = buildTree(str, n);
    vi lcp = lcpUtil(str, suffixArr);
    fl(i,0,lcp.size()){
        int charToSkip = firstNsum(n - suffixArr[i]) -
                         firstNsum(lcp[i]);
        if (K <= charToSkip){
            for (int j = lcp[i] + 1; j <= (n-suffixArr[i]); j++){
                int curSubstringLen = j;
 
                if (K <= curSubstringLen)
                    return str[(suffixArr[i] + K - 1)];
                else
                    K -= curSubstringLen;
 
            }
            break;
        }
        else
            K -= charToSkip;
     }
}
 
int main()
{
    Int t,p,g = 0,m;
    string s;
    cin>>s>>t;
    while(t--){
        cin>>p>>m;
        int k = ((p%m)*(g%m))%m+1;
        char ans = solve(s,k);
        cout<<ans<<endl;
        g += ans;
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