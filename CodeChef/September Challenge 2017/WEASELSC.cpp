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
#define MOD 1000000007
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

Int T,N,K;

int main(){
	ios;
	cin>>T;
	while(T--){
		cin>>N>>K;
		Int height,width;
		vi arr(N);
		si_d area;
		area.insert(0);
		vvi se(2);
		se[0].pb(0);
		fl(i,0,N){
			cin>>arr[i];
			if(arr[i]==0){
				se[1].pb(i-1);
				se[0].pb(i+1);
			}
		}
		se[1].pb(N-1);
		fl(i,0,se[0].size()){
			fl(k,se[0][i],se[1][i]+1){
				height = arr[k];
				width = 1;
				fl(j,k+1,se[1][i]+1){
					if(arr[j]>=height)	width++;
					else 	break;
				}
				for(Int j=k-1;j>=se[0][i];j--){
					if(arr[j]>=height)	width++;
					else 	break;
				}
				area.insert(height*width);
			}
		}
		cout<<*area.begin()<<endl;
	}

	return 0;
}