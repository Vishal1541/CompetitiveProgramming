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

int T;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		int arr[N],idx,count=0;
		fl(i,0,N){
			cin>>arr[i];
		}
		string s;
		cin>>s;
		fl(i,0,s.length()){
			if(s[i]=='1')	count++;
			if(count==3){
				idx = i;
				break;
			}
		}
		idx = (idx+1)%(N);
		int R,rem,ans;
		cin>>R;
		rem = N-idx;
		if(R-rem>0){
			ans = arr[R-rem-1];
		}
		else{
			ans = arr[idx+R-1];
		}
		cout<<ans<<endl;
	}


	return 0;
}