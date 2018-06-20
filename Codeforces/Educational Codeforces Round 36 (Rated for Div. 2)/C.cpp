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

string a,b;
vector<string> ans;
int alen,blen;
vi flag(50,0);

bool cmp(const int& a, const int& b){
    return a>b;
}
bool cmpstr(const string& a, const string& b){
    if(a.compare(b)>0)  return true;
    return false;
}

bool solve(string& str, int idxb, int& lastused){
    if(idxb==blen){
        ans.pb(str);
        return true;
    }
    int maxx = -1, ptr;
    for(int i=0; i<alen; i++){
        if(idxb==0){
            if(a[i]!='0' && a[i]<=b[0] && a[i]<lastused){
                if((int)a[i]>maxx){
                    maxx = (int)a[i];
                    ptr = i;
                }
            }
        }
        else{
            if(a[i]<=b[idxb] && a[i]<lastused && !flag[i]){
                if((int)a[i]>maxx){
                    maxx = (int)a[i];
                    ptr = i;
                }
            }   
        }
        cout<<str<<endl;
    }
    if(maxx==-1)    return false;
    // cout<<a[ptr]<<" ";
    flag[ptr] = 1;
    str += a[ptr];
    if(a[ptr]<b[idxb]){
        // cout<<"yes";
        string temp = "";
        for(int i=0; i<alen; i++){
            if(!flag[i])    temp += a[i];
        }
        sort(temp.begin(), temp.end(), cmp);
        str += temp;
        ans.pb(str);
        return true;
    }
    int l = 999;
    bool ret = solve(str,idxb+1,l);
    if(!ret){
        string temp = "";
        for(int i=0; i<str.length()-1; i++) temp += str[i];
        flag[ptr] = 0;
        l = str[str.length()-1];
        ret = solve(temp,idxb,l);
        if(!ret){
            lastused = str[str.length()-1];
            return false;
        }
    }
}

int main(){
    ios;
    cout.precision(10);
    cout<<fixed;

    cin>>a>>b;
    if(a.length()<b.length()){
        sort(a.begin(), a.end(), cmp);
        cout<<a;
        return 0;
    }
    alen = blen = a.length();
    string str = "";
    int l = 999;
    bool ret = solve(str,0,l);
    sort(ans.begin(), ans.end(), cmpstr);
    cout<<ans[0];
    // int len = a.length();
    // vi flag(len,0);
    // string ans = "";
    // int maxx, ptr;
    // for(int i=0; i<b.length(); i++){
    //     maxx = 0;
    //     for(int j=0; j<len; j++){
    //         if(i==0){
    //             if(a[j]!='0' && a[j]<=b[0]){
    //                 maxx = max(maxx,a[j]);
    //                 cout<<a[j]<<"->"<<(int)(a[j])<<" ";
    //                 ptr = j;
    //             }       
    //         }
    //         else{
    //             if(a[j]<=b[i] && !flag[j]){
    //                 maxx = max(maxx,a[j]);
    //                 ptr = j;
    //             }  
    //         }
    //     }
    //     flag[ptr] = 1;
    //     ans += a[ptr];
    //     // cout<<a[ptr]<<" ";
    //     if(a[ptr]<b[i]){
    //         string temp = "";
    //         for(int j=0; j<len; j++){
    //             if(!flag[j])    temp += a[j];
    //         }
    //         sort(temp.begin(), temp.end(), cmp);
    //         ans += temp;
    //         break;
    //     }
    // }
    // cout<<ans;

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