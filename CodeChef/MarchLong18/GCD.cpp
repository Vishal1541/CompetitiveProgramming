//VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TC int t;scanf("%d",&t);while (t-->0)
#define Int int
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

const int MAX = 1e5+7, SQSIZE = 250;
int n,q,x,y,l,r,g,type,input[MAX],blk_size,lastPtr[SQSIZE] = {0},ans;
vector<bool> P(MAX,1);
vvi fact(MAX);
vector<set<int> > block[SQSIZE];
set<int> :: iterator itr;
mii numIdx[SQSIZE], idxNum[SQSIZE], occurrences[SQSIZE];
map<pair<int,int>, int> weights[SQSIZE];

void update(){
    int blk_num = x / blk_size;
    int p1 = 0, p2 = 0;
    fl(i,0,fact[input[x]].size()){
        if(i==0)    occurrences[blk_num][fact[input[x]][i]]--;
        p1 = numIdx[blk_num][fact[input[x]][i]];
        fl(j,i+1,fact[input[x]].size()){
            if(i==0)    occurrences[blk_num][fact[input[x]][j]]--;
            p2 = numIdx[blk_num][fact[input[x]][j]];
            weights[blk_num][{p1,p2}]--;
            weights[blk_num][{p2,p1}]--;
        }
    }
    int i = x;
    int blk_idx = blk_num;
    input[i] = y;
    fl(j,0,fact[input[i]].size()){
        p1 = numIdx[blk_idx][fact[input[i]][j]];
        if(!p1){
            p1 = ++lastPtr[blk_idx];
            numIdx[blk_idx][fact[input[i]][j]] = lastPtr[blk_idx];
            idxNum[blk_idx][lastPtr[blk_idx]] = fact[input[i]][j];
        }
        if(j==0){
            occurrences[blk_idx][fact[input[i]][j]]++;
        }
        fl(k,j+1,fact[input[i]].size()){
            if(j==0){
                occurrences[blk_idx][fact[input[i]][k]]++;
            }
            p2 = numIdx[blk_idx][fact[input[i]][k]];
            if(!p2){
                p2 = ++lastPtr[blk_idx];
                numIdx[blk_idx][fact[input[i]][k]] = lastPtr[blk_idx];
                idxNum[blk_idx][lastPtr[blk_idx]] = fact[input[i]][k];
            }
            block[blk_idx][p2].insert(p1);
            block[blk_idx][p1].insert(p2);
            weights[blk_idx][{p1,p2}]++;
            weights[blk_idx][{p2,p1}]++;
        }
    }
}

void query(){
    int ones = 0, common = 0, A;
    int times = 0, L = l, R = r;
    while(l<r && l%blk_size!=0 && l!=0){
        A = input[l];
        if(gcd(max(A,g),min(A,g))==1){
            ones++;
            // cout<<"ok";
        }
        l++;
        times++;
    }
    while(l+blk_size <= r){
        int blk_idx = l / blk_size;
        // times++;
        mii visit, tempOccr;
        map<pair<int,int>,int > wei;
        fl(i,0,fact[g].size()){
            int p1 = numIdx[blk_idx][fact[g][i]];
            if(p1==0) continue;
            if(occurrences[blk_idx][idxNum[blk_idx][p1]]==tempOccr[p1])  continue;
            // cout<<fact[g][i]<<" "<<l<<endl;
            visit[p1] = 1;
            common += occurrences[blk_idx][idxNum[blk_idx][p1]] - tempOccr[p1];
            foreach(itr,block[blk_idx][p1]){
                int p2 = *itr;
                if(visit[p2])   continue;
                tempOccr[p2] += weights[blk_idx][{p1,p2}];
                // wei[{p1,p2}] = weights[blk_idx][{p1,p2}];
            }
        }
        l += blk_size;
    }
    while(l<=r){
        // cout<<l<<" ";
        A = input[l];
        if(gcd(max(A,g),min(A,g))==1){
            ones++;
            // cout<<"ok";
        }
        times++;
        l++;
    }
    // cout<<ones<<"_"<<common<<"_";
    ans = ones + (R-L+1-times-common);
}

void precalc(){
    int blk_idx = -1;
    blk_size = sqrt(n);
    fl(i,0,SQSIZE)  lastPtr[i] = 0;
    fl(i,0,n){
        if(i%blk_size==0)   blk_idx++;
        int p1 = 0, p2 = 0;
        fl(j,0,fact[input[i]].size()){
            p1 = numIdx[blk_idx][fact[input[i]][j]];
            if(p1==0){
                p1 = ++lastPtr[blk_idx];
                numIdx[blk_idx][fact[input[i]][j]] = lastPtr[blk_idx];
                idxNum[blk_idx][lastPtr[blk_idx]] = fact[input[i]][j];
            }
            if(j==0){
                occurrences[blk_idx][fact[input[i]][j]]++;
            }
            fl(k,j+1,fact[input[i]].size()){
                if(j==0){
                    occurrences[blk_idx][fact[input[i]][k]]++;
                }
                p2 = numIdx[blk_idx][fact[input[i]][k]];
                if(p2==0){
                    p2 = ++lastPtr[blk_idx];
                    numIdx[blk_idx][fact[input[i]][k]] = lastPtr[blk_idx];
                    idxNum[blk_idx][lastPtr[blk_idx]] = fact[input[i]][k];
                }
                block[blk_idx][p2].insert(p1);
                block[blk_idx][p1].insert(p2);
                weights[blk_idx][{p1,p2}]++;
                weights[blk_idx][{p2,p1}]++;
            }
        }
    }
}

int main(){
    ios;
    cout.precision(10);
    cout<<fixed;

    fl(i,0,SQSIZE)  block[i].resize(400);
    fl(i,2,MAX){
        if(P[i]){
            fact[i].pb(i);
            for(int j=2*i; j<MAX; j+=i){
                P[j] = 0;
                fact[j].pb(i);
            }
        }
    }
    cin>>n;
    fl(i,0,n)   cin>>input[i];
    precalc();
    cin>>q;
    while(q--){
        cin>>type;
        if(type==1){
            cin>>x>>y;
            x--;
            update();
        }
        else{
            cin>>l>>r>>g;
            l--,r--;
            ans = 0;
            query();
            cout<<ans<<endl;
        }
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