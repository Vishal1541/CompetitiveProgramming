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

struct sq{
    int x[4], y[4];
};

struct line{
    int x,y,c;
};

sq A,a;
line l1,l2,l3,l4,L1,L2,L3,L4;
int C, sign[4][4],Sign[4][4], Plus, Minus;  //point x line
bool yes = 0;
bool correct[4];

bool isOpposite(int a, int b){
    return ( (a==1 && b==-1)
        ||  (a==-1 && b==1));
}

bool isInside(int x, int y){
    sign[0][0] = (x*l1.x + y + l1.c >= 0? 1 : -1);
    sign[0][1] = (x*l2.x + y + l2.c >= 0? 1 : -1);
    sign[0][2] = (x*l3.x + y + l3.c >= 0? 1 : -1);
    sign[0][3] = (x*l4.x + y + l4.c >= 0? 1 : -1);

    if(isOpposite(sign[0][0],sign[0][2]) && isOpposite(sign[0][1],sign[0][3]))
        yes = 1;
}

int main(){
    ios;
    cout.precision(10);
    cout<<fixed;

    fl(i,0,4)   cin>>A.x[i]>>A.y[i];
    fl(i,0,4)   cin>>a.x[i]>>a.y[i];

    C = (a.y[1] - a.y[0]) / (a.x[1] - a.x[0]);
    l1.x = -C;
    l1.y = 1;
    l1.c = a.x[1]*C - a.y[1];

    C = (a.y[2] - a.y[1]) / (a.x[2] - a.x[1]);
    l2.x = -C;
    l2.y = 1;
    l2.c = a.x[2]*C - a.y[2];

    C = (a.y[3] - a.y[2]) / (a.x[3] - a.x[2]);
    l3.x = -C;
    l3.y = 1;
    l3.c = a.x[3]*C - a.y[3];

    C = (a.y[0] - a.y[3]) / (a.x[0] - a.x[3]);
    l4.x = -C;
    l4.y = 1;
    l4.c = a.x[0]*C - a.y[0];

    if(A.x[0] == A.x[1]){
        L1.x = -1;
        L1.y = 0;
        L1.c = A.x[0];
    }
    else{
        L1.x = 0;
        L1.y = 1;
        L1.c = -A.y[0];
    }

    if(A.x[1] == A.x[2]){
        L2.x = -1;
        L2.y = 0;
        L2.c = A.x[1];
    }
    else{
        L2.x = 0;
        L2.y = 1;
        L2.c = -A.y[1];
    }

    if(A.x[2] == A.x[3]){
        L3.x = -1;
        L3.y = 0;
        L3.c = A.x[2];
    }
    else{
        L3.x = 0;
        L3.y = 1;
        L3.c = -A.y[2];
    }

    if(A.x[3] == A.x[0]){
        L4.x = -1;
        L4.y = 0;
        L4.c = A.x[3];
    }
    else{
        L4.x = 0;
        L4.y = 1;
        L4.c = -A.y[3];
    }

    // l1
    fl(i,0,4){
        sign[i][0] = (A.x[i]*l1.x + A.y[i] + l1.c >= 0? 1 : -1);
    }
    // l2
    fl(i,0,4){
        sign[i][1] = (A.x[i]*l2.x + A.y[i] + l2.c >= 0? 1 : -1);
    }
    // l3
    fl(i,0,4){
        sign[i][2] = (A.x[i]*l3.x + A.y[i] + l3.c >= 0? 1 : -1);
    }
    // l4
    fl(i,0,4){
        sign[i][3] = (A.x[i]*l4.x + A.y[i] + l4.c >= 0? 1 : -1);
    }

    // L1
    fl(i,0,4){
        Sign[i][0] = (a.x[i]*L1.x + a.y[i]*L1.y + L1.c >= 0? 1 : -1);
    }
    // L2
    fl(i,0,4){
        Sign[i][1] = (a.x[i]*L2.x + a.y[i]*L2.y + L2.c >= 0? 1 : -1);
    }
    // L3
    fl(i,0,4){
        Sign[i][2] = (a.x[i]*L3.x + a.y[i]*L3.y + L3.c >= 0? 1 : -1);
    }
    // L2
    fl(i,0,4){
        Sign[i][3] = (a.x[i]*L4.x + a.y[i]*L4.y + L4.c >= 0? 1 : -1);
    }

    // fl(i,0,4){
    //     fl(j,0,4)   cout<<Sign[i][j]<<" ";
    //     cout<<endl;
    // }

    fl(i,0,4){
        if(isOpposite(sign[i][0],sign[i][2]) 
            && isOpposite(sign[i][1],sign[i][3])){
            yes = 1;
        break;
        }
        if(isOpposite(Sign[i][0],Sign[i][2]) 
            && isOpposite(Sign[i][1],Sign[i][3])){
            yes = 1;
        break;
        }
    }

    if(A.x[0] == A.x[1]){
        for(int i=min(A.y[0],A.y[1]); i<=max(A.y[0],A.y[1]); i++){
            if(isInside(A.x[0],i))  yes = 1;
        }
    }
    else{
        for(int i=min(A.x[0],A.x[1]); i<=max(A.x[0],A.x[1]); i++){
            if(isInside(i,A.y[0]))  yes = 1;
        }
    }

    if(A.x[1] == A.x[2]){
        for(int i=min(A.y[1],A.y[2]); i<=max(A.y[1],A.y[2]); i++){
            if(isInside(A.x[1],i))  yes = 1;
        }
    }
    else{
        for(int i=min(A.x[1],A.x[2]); i<=max(A.x[1],A.x[2]); i++){
            if(isInside(i,A.y[1]))  yes = 1;
        }
    }

    if(A.x[2] == A.x[3]){
        for(int i=min(A.y[2],A.y[3]); i<=max(A.y[2],A.y[3]); i++){
            if(isInside(A.x[2],i))  yes = 1;
        }
    }
    else{
        for(int i=min(A.x[2],A.x[3]); i<=max(A.x[2],A.x[3]); i++){
            if(isInside(i,A.y[2]))  yes = 1;
        }
    }

    if(A.x[3] == A.x[0]){
        for(int i=min(A.y[3],A.y[0]); i<=max(A.y[3],A.y[0]); i++){
            if(isInside(A.x[3],i))  yes = 1;
        }
    }
    else{
        for(int i=min(A.x[3],A.x[0]); i<=max(A.x[3],A.x[0]); i++){
            if(isInside(i,A.y[3]))  yes = 1;
        }
    }

    // fl(i,0,4){
    //     fl(j,0,4){
    //         if(A.x[i] == a.x[i] && A.y[i] == a.y[i])    yes = 1;
    //     }
    // }

    // fl(j,0,4){
    //     Plus = Minus = 0;
    //     fl(i,0,4){
    //         if(sign[i][j] == 1) Plus++;
    //         else    Minus++;
    //     }
    //     if((Plus==3 && Minus==1) || (Plus==1 && Minus==3) ){
    //         correct[j] = 1;
    //     }
    //     else{
    //         correct[j] = 0;
    //     }
    // }

    // bool allCorrect = 1;

    // fl(i,0,4){
    //     if(correct[i] == 0) allCorrect = 0;
    // }

    // if(allCorrect)  yes = 1;

    cout<<(yes?"YES\n":"NO\n")<<endl;

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