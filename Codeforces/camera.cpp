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

Int n,k,r,inp,b,f,temp,added=0,current=0;
vi flag(100009,0);

int main(){
	ios;
	cin>>n>>k>>r;
	fl(i,0,k){
		cin>>inp;
		flag[inp-1] = 1;
	}
	fl(i,0,r-1)	if(flag[i])	current++;
	b=0,f=r-1;
	while(f<n){
		if(flag[f]){
			current++;
		}
		temp = f;
		while(current<2){
			if(!flag[temp]){
				flag[temp] = 1;
				current++;
				added++;
			}
			temp--;
		}
		if(flag[b]){
			flag[b] = 0;
			current--;
		}
		b++,f++;
	}
	cout<<added<<endl;

	return 0;
}