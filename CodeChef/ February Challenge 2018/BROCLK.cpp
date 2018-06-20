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

int T;
Int t,p,q,r,l,d,y,ptr,lcostx[109],costx[109],cospow[109],sinpow[109],sumPow[109];
// long double l,d,x0,theta,y;


void extEucl(Int a, Int b, Int& x, Int& y){
    if(a%b==0){
        x = 0, y = 1;
        return;
    }
    extEucl(b,a%b,x,y);
    Int temp = x;
    x = y;
    y = temp - y*(a/b);
}

Int inverse(Int a, Int m){
    Int x,y;
    extEucl(a,m,x,y);
    if(x<0) x+=m;
    return x;
}

Int order(Int p, Int b){
    if (gcd(p, b) != 1){
        return -1;
    }
    Int k = 3;
    while (1)
    {
        if (powerMod(b, k, p) == 1)
            return k;
        k++;
    }
}

Int convertx2e(Int x, Int& e)
{
    e = 0;
    while (x % 2 == 0)
    {
        x /= 2;
        e++;
    }
    return x;
}

Int STonelli(Int n, Int p){
    if (gcd(n, p) != 1){
        return -1;
    }
    if (powerMod(n, (p - 1) / 2, p) == (p - 1)){
        return -1;
    }
    Int s, e;
    s = convertx2e(p - 1, e);
    Int q;
    for (q = 2; ; q++){
        // q - 1 is in place of  (-1 % p)
        if (powerMod(q, (p - 1) / 2, p) == (p - 1))
            break;
    }
    Int x = powerMod(n, (s + 1) / 2, p);
    Int b = powerMod(n, s, p);
    Int g = powerMod(q, s, p);
 
    Int r = e;
    while (1){
        Int m;
        for (m = 0; m < r; m++){
            if (order(p, b) == -1)
                return -1;
            if (order(p, b) == raiseToPow(2, m))
                break;
        }
        if (m == 0)
            return x;
        x = (x * powerMod(g, raiseToPow(2, r - m - 1), p)) % p;
        g = powerMod(g, raiseToPow(2, r - m), p);
        b = (b * g) % p;
 
        if (b == 1)
            return x;
        r = m;
    }
}



int main(){

    // cin>>T;
    scanf("%d",&T);
    while(T--){
        // cin>>l>>d>>t;
        scanf("%lld%lld%lld",&l,&d,&t);
        Int nu,de,r;
        lcostx[1] = d;
        costx[1] = (lcostx[1]*powerMod(l,MOD-2,MOD))%MOD;
        nu = (2*d*d-l*l)%MOD;
        de = l;
        r = powerMod(de,MOD-2,MOD);
        lcostx[2] = ((nu%MOD)*(r%MOD))%MOD;
        lcostx[2] = (lcostx[2]+MOD)%MOD;
        costx[2] = (lcostx[2]*powerMod(l,MOD-2,MOD))%MOD;
        Int twoP = log2(t);
        Int rem = t - raiseToPow(2,twoP);
        cospow[0] = costx[1];
        cospow[1] = costx[2];
        lcostx[0] = lcostx[1];
        lcostx[1] = lcostx[2];
        Int rr = STonelli(l*l-d*d,MOD);
        if(rr==-1){

            fl(i,2,twoP+1){
                cospow[i] = (2*cospow[i-1]*cospow[i-1]-1+MOD)%MOD;
                cospow[i] = (cospow[i]+MOD)%MOD;
                lcostx[i] = (cospow[i]*l)%MOD;
            }
            if(!rem){
                // cout<<lcostx[twoP]<<endl;
                printf("%lld\n", lcostx[twoP]);
                continue;
            }
            Int CosC = cospow[twoP];
            Int CosD = (2*cospow[twoP]*cospow[twoP]-1+MOD)%MOD;
            Int C = raiseToPow(2,twoP), D = raiseToPow(2,twoP+1), CosE, E;
            Int turn = 1, ans;
            while(1){
                E = (C+D)/2;
                Int r = powerMod(2*cospow[twoP-turn],MOD-2,MOD);
                Int nu = CosC + CosD;
                // Int de = 2*cospow[twoP-turn];
                // Int div = gcd(max(nu,de),min(nu,de));
                // nu /= div, de /= div;
                // Int r = inverse(de,MOD);
                CosE = (((nu)%MOD)*(r%MOD))%MOD;
                if(E==t)    break;
                if(E>t) {D = E, CosD = CosE;}
                else    {C = E, CosC = CosE;}
                turn++;
            }
            ans = (CosE*l)%MOD;
            // cout<<ans<<endl;
            printf("%lld\n", ans);
            continue;

        }
        sinpow[0] = (((rr)%MOD)*(powerMod(l,MOD-2,MOD)%MOD))%MOD;
        sinpow[0] = (sinpow[0]+MOD)%MOD;
        sinpow[1] = (((2*sinpow[0])%MOD)*(cospow[0]%MOD))%MOD;
        sinpow[1] = (sinpow[1]+MOD)%MOD;
        fl(i,2,twoP+1){
            cospow[i] = (2*cospow[i-1]*cospow[i-1]-1+MOD)%MOD;
            cospow[i] = (cospow[i]+MOD)%MOD;
            sinpow[i] = (((2*sinpow[i-1])%MOD)*(cospow[i-1]%MOD))%MOD;
            sinpow[i] = (sinpow[i]+MOD)%MOD;
        }
        ptr = -1;
        Int t_ = t, pp = 0;
        while(t_){
            if(t_%2){
                sumPow[++ptr] = pp;
            }
            t_ /= 2;
            pp++;
        }
        // fl(i,0,ptr+1)   cout<<sumPow[i]<<"_";
        Int A,B,cosA_B, sinA_B = 0, ans = 0;
        if(ptr==0){
            ans = (l*cospow[sumPow[ptr]])%MOD;
            ans = (ans+MOD)%MOD;
        }
        else{
            A = sumPow[ptr], B = sumPow[ptr-1];
            ptr -= 2;
            // cout<<A<<"_"<<B<<"_";
            cosA_B = (cospow[A]*cospow[B]-sinpow[A]*sinpow[B])%MOD;
            cosA_B = (cosA_B+MOD)%MOD;
            sinA_B = (sinpow[A]*cospow[B]+cospow[A]*sinpow[B])%MOD;
            sinA_B = (sinA_B+MOD)%MOD;
            while(ptr>=0){
                B = sumPow[ptr];
                Int tCos = cosA_B;
                cosA_B = (cosA_B*cospow[B]-sinA_B*sinpow[B])%MOD;
                cosA_B = (cosA_B+MOD)%MOD;
                sinA_B = (sinA_B*cospow[B]+tCos*sinpow[B])%MOD;
                sinA_B = (sinA_B+MOD)%MOD;
                ptr--;
            }
            ans = (l*cosA_B)%MOD;
            ans = (ans+MOD)%MOD;
        }
        // cout<<ans<<endl;
        printf("%lld\n", ans);
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