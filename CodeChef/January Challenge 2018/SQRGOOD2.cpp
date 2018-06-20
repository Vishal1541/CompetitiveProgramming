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

Int raiseToPow(Int x, Int power);

//10^14th --> 255054609673752
const Int N = 30000000, Imax = 30000000;
Int I, D, n, l, h, m, now;
Int prime[N], mu[N], M[N], sumOverM[N], X[N];

void solveMobius(Int a, Int k){
    fl(i,0,k-a+1)   mu[i] = 0;
    mu[1] = 1;
    fl(i,0,k-a+1){
        if (!prime[i]) prime[++prime[0]] = i, mu[i] = -1;
        for (int j = 1, k = (k - 1) / i, t; prime[j] <= k; ++j) {
            prime[t = i * prime[j]] = 1;
            if (i % prime[j]) mu[t] = -mu[i];
            else {mu[t] = 0; break;}
        }
    }
}

void solveForMarr(Int a, Int k){
    M[0] = mu[0];
    for(int i=1; i<k-a+1; i++){
        M[i] = M[i-1] + mu[i];
    }
}

Int solve(Int k){
	Int ans = 0, test;
	I = cbrt(k/4);
	for(int i=1; i<=I; i++){
    	X[i] = sqrt(k/i);
    }
	D = X[I];
    Int sqD = sqrt(D);
    Int a = 1, b = sqD;
    for (Int j = 1; j <= sqD; ++j){
        solveMobius(a,b);
        fl(i,0,b-a){
        	test = (k / (i*i));
            ans += test * mu[i];
        }
        a += sqD;
        b += sqD;
    }
    test = (k / (D*D));
    ans += test * mu[D*D-D];

    // ans += sumOverM[X[I-1]] - (I-1)*M[X[I]];
    for(Int j=1; j<I; j++){

    	ans += M[X[i]];
    }
    ans -= (I-1)*M[X[I]];
    if(k==1 || k==2 || k==3) ans = k;
    return k-ans;
}

int main(){

    scanf("%lld",&n);
    
    // sumOverM[X[1]] = M[X[1]];
    // for(int i=2; i<=Imax; i++){
    // 	sumOverM[X[i]] = sumOverM[X[i-1]] + M[X[i]];
    // }
    if(n<=4){
    	Int ans;
    	if(n==1)	ans = 4;
    	else if(n==2)	ans = 8;
    	else if(n==3)	ans = 9;
    	else 	ans = 12;
    	cout<<ans;
    	return 0;
    }
    l = 1, h = 4*n;
    m = (l+h)/2;
    now = solve(m);
    // cout<<now<<endl;
    while(h-l>1){
    	if(now<n){
    		l = m;
    	}
    	else if(now>n){
    		h = m;
    	}
    	else{
    		break;
    	}
    	m = ceil((l+h)/2.0);
    	now = solve(m);
    }
    if(now>=n){
    	while(now>=n){
    		m--;
    		now = solve(m);
    	}
    	m++;
    }
    else{
    	while(now<n){
    		m++;
    		now = solve(m);
    	}
    }
    cout<<m<<endl;
    // I = cbrt(n/4);
   	// D = X[I];
   	// cout<<solve(D)<<endl;

    #ifndef LOCAL_DEFINE
        cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
    #endif

    return 0;
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

