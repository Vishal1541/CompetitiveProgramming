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
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

string s;
vi visited(100009,0);
vi visited2(100009,0);

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>s;
	bool found1 = false, found2 = false, found3 = false, found4 = false;
	if(s.length()==1){
		cout<<"NO\n";
		return 0;
	}
	fl(i,0,s.length()-1){
		if(s[i]=='A' && !visited[i] && s[i+1]=='B' && !visited[i+1]){
			found1 = true;
			visited[i]=1,visited[i+1]=1;
			break;
		}
	}
	fl(i,0,s.length()-1){
		if(s[i]=='B' && !visited[i] && s[i+1]=='A' && !visited[i+1]){
			found2 = true;
			visited[i]=1,visited[i+1]=1;
			break;
		}
	}


	fl(i,0,s.length()-1){
		if(s[i]=='B' && !visited2[i] && s[i+1]=='A' && !visited2[i+1]){
			found3 = true;
			visited2[i]=1,visited2[i+1]=1;
			break;
		}
	}
	fl(i,0,s.length()-1){
		if(s[i]=='A' && !visited2[i] && s[i+1]=='B' && !visited2[i+1]){
			found4 = true;
			visited2[i]=1,visited2[i+1]=1;
			break;
		}
	}
	cout<<(((found1&&found2) || (found3&&found4)) ?"YES\n":"NO\n");

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}