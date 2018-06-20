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
#define us unordered_set
#define um unordered_map
#define mii map<Int,Int>
#define qi queue<Int>
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define PI 3.141592653589793238L
#define F first
#define S second
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define mp make_pair
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int n,m;

Int Pow(Int x, Int power)
{
    Int result;
    Int i;
    result =1.0;
    for (i=1; i<=power;i++)
    {
        result = result*x;
    }
    return(result);
}

int main(){
	ios;
	cin>>n>>m;
	Int ones,zeros,ans=0;
	int arr[n][m];
	fl(i,0,n)	fl(j,0,m)	cin>>arr[i][j];
	fl(i,0,n){
		ones=zeros=0;
		fl(j,0,m){
			if(arr[i][j])	ones++;
			else 			zeros++;
		}
		ans+=Pow(2,ones)-1;
		ans+=Pow(2,zeros)-1;
	}
	fl(j,0,m){
		ones=zeros=0;
		fl(i,0,n){
			if(arr[i][j])	ones++;
			else 			zeros++;
		}
			ans+=Pow(2,ones)-1-ones;
			ans+=Pow(2,zeros)-1-zeros;
	}
	cout<<ans<<endl;

	return 0;
}