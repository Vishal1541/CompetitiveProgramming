//VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TC int t;scanf("%d",&t);while (t-->0)
#define Int long long int
#define ld long double
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

const int MAX = 1007;
int T,N,M;
Int arr[MAX][MAX],ud[MAX][MAX],du[MAX][MAX],lr[MAX][MAX],rl[MAX][MAX];
bool isud[MAX][MAX], isdu[MAX][MAX], islr[MAX][MAX], isrl[MAX][MAX];

bool isUpCorner(int i, int j){
    return (i==1);
}

bool isDownCorner(int i, int j){
    return (i==N-2);
}

bool isLeftCorner(int i, int j){
    return (j==1);
}

bool isRightCorner(int i, int j){
    return (j==M-2);
}

int main(){
    ios;
    cout.precision(10);
    cout<<fixed;

    cin>>T;
    while(T--){
        Int ans = -9999999999999;
        cin>>N>>M;
        fl(i,0,N){
            fl(j,0,M){
                cin>>arr[i][j];
                isud[i][j] = isdu[i][j] = islr[i][j] = isrl[i][j] = 0;
            }
        }

        fl(j,0,M){
            ud[0][j] = arr[0][j];
            fl(i,1,N){
                ud[i][j] = max(ud[i-1][j] + arr[i][j], arr[i][j]);
                if(ud[i-1][j] + arr[i][j] >= arr[i][j]) isud[i][j] = 1;
                else    isud[i][j] = 0;
            }
            du[N-1][j] = arr[N-1][j];
            for(int i=N-2; i>=0; i--){
                du[i][j] = max(du[i+1][j] + arr[i][j], arr[i][j]);
                if(du[i+1][j] + arr[i][j] >= arr[i][j])  isdu[i][j] = 1;
                else isdu[i][j] = 0;
            }
        }

        fl(i,0,N){
            lr[i][0] = arr[i][0];
            fl(j,1,M){
                lr[i][j] = max(lr[i][j-1] + arr[i][j], arr[i][j]);
                if(lr[i][j-1] + arr[i][j] >= arr[i][j]) islr[i][j] = 1;
                else    islr[i][j] = 0;
            }
            rl[i][M-1] = arr[i][M-1];
            for(int j=M-2; j>=0; j--){
                rl[i][j] = max(rl[i][j+1] + arr[i][j], arr[i][j]);
                if(rl[i][j+1] + arr[i][j] >= arr[i][j]) isrl[i][j] = 1;
                else    isrl[i][j] = 0;
            }
        }

        fl(i,1,N-1){
            fl(j,1,M-1){
                Int temp = 0, temp2;
                if(!isud[i][j]){
                    temp += arr[i][j] + arr[i-1][j];
                    temp2 = temp;
                    for(int l=i-2; l>=0; l--){
                        temp2 += arr[l][j];
                        temp = max(temp, temp2);
                    }
                }
                else    temp += ud[i][j];

                if(!isdu[i][j]){
                    temp += arr[i][j] + arr[i+1][j];
                    temp2 = temp;
                    for(int l=i+2; l<N; l++){
                        temp2 += arr[l][j];
                        temp = max(temp, temp2);
                    }
                }
                else    temp += du[i][j];

                if(!islr[i][j]){
                    temp += arr[i][j] + arr[i][j-1];
                    temp2 = temp;
                    for(int l=j-2; l>=0; l--){
                        temp2 += arr[i][l];
                        temp = max(temp, temp2);
                    }
                }
                else    temp += lr[i][j];

                if(!isrl[i][j]){
                    temp += arr[i][j] + arr[i][j+1];
                    temp2 = temp;
                    for(int l=j+2; l<M; l++){
                        temp2 += arr[i][l];
                        temp = max(temp, temp2);
                    }
                }
                else    temp += rl[i][j];

                temp -= (3*arr[i][j]);
                ans = max(ans, temp);
            }
        }
        cout<<ans<<endl;
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

Int raiseToPow(Int x, Int y)
{
    Int res = 1;     // Initialize result
  
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;
  
        // n must be even now
        y /= 2; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
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