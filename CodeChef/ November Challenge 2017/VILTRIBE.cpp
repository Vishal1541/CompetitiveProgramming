//    VISHAL ANAND
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
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int t;
string s;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>t;
	while(t--){
		cin>>s;
		vector<pair<char,int> > arr;
		int As = 0, Bs = 0;
		fl(i,0,s.length()){
			if(s[i]!='.')	arr.pb(make_pair(s[i],i));
		}
		fl(i,0,arr.size()){
			int i1,i2;
			if(arr[i].F=='A'){
				i1 = arr[i].S;
				while(arr[i].F=='A'){
					i++;
					if(i==arr.size())	break;
				}
				i2 = arr[i-1].S;
				As += i2-i1+1;
			}
			else{
				i1 = arr[i].S;
				while(arr[i].F=='B'){
					i++;
					if(i==arr.size())	break;
				}
				i2 = arr[i-1].S;
				Bs += i2-i1+1;
			}
			i--;
		}
		cout<<As<<" "<<Bs<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}