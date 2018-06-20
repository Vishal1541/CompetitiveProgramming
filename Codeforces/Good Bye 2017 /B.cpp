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
Int nextPowerOf2(Int n);
Int raiseToPow(Int x, Int power);
Int powerMod(Int x, Int y, Int p);
void primeFactors(Int n);

int n,m,ans = 0;
int start[2],End[2];
char arr[55][55], U,D,L,R;
string instruction;
bool reached;

bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && arr[i][j]!='#');
}

void traverse(int i, int j, int code){
    if(!isValid(i,j))   return;
    if(arr[i][j]=='E'){
        reached = true;
        return;
    }
    char dir = instruction[code];
    dir = dir - '0';
    if(dir==U)  traverse(i-1,j,code+1);
    else if(dir==D)  traverse(i+1,j,code+1);
    else if(dir==L)  traverse(i,j-1,code+1);
    else if(dir==R)  traverse(i,j+1,code+1);
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

    cin>>n>>m;
    fl(i,0,n){
        fl(j,0,m){
            cin>>arr[i][j];
            if(arr[i][j]=='S')  start[0] = i, start[1] = j;
            if(arr[i][j]=='E')  End[0] = i, End[1] = j;
        }
    }
    cin>>instruction;
    for(int u=0; u<=3; u++){
        for(int d=0; d<=3; d++){
            if(u!=d){
                for(int l=0; l<=3; l++){
                    if(l!=d && l!=u){
                        for(int r=0; r<=3; r++){
                            if(r!=l && r!=d && r!=u){
                                U = u, D = d, L = l, R = r;
                                reached = false;
                                traverse(start[0],start[1],0);
                                if(reached) ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
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