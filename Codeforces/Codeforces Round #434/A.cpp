//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
#define MOD 1000000007
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int n,temp,k,two=0,five=0,already,diff,need2,need5;
msi factors;
msi_it itr;

void primeFactors(Int n)
{
    while (n%2 == 0)
    {
        factors.insert(2);
        n = n/2;
    }
    for (Int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            factors.insert(i);
            n = n/i;
        }
    }
    if (n > 2)
        factors.insert(n);
}

int main(){
	ios;
	cin>>n>>k;
	temp = n;
	primeFactors(temp);
	foreach(itr,factors){
		if(*itr==2)	two++;
		else if(*itr==5)	five++;
	}
	already = min(two,five);
	diff = k-already;
	if(diff>0){
		need2 = k- two;
		need5 = k- five;
		if(need2>0)	n = n*pow(2,need2);
		if(need5>0)	n = n*pow(5,need5);
	}
	cout<<n<<endl;

	return 0;
}