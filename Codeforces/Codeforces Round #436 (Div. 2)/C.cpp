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

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	int a,b,b_,f,k,count = 0,trip=1;
	bool filled = false;
	cin>>a>>b>>f>>k;
	b_ = b;

	while(k--){
		if(trip%2==1){
			if(b_-f<0){
				if(filled){
					cout<<"-1\n";
					return 0;
				}
				if(trip>1){
					b_ = b-2*f;
					count++;
					if(b_<0){
						cout<<"-1\n";
						return 0;
					}
				}
				else if(trip==1){
					cout<<"-1\n";
					return 0;
				}
			}
			else{
				filled = false;
				b_ -=f;
			}
			if(b_<a-f){
				if(filled){
					cout<<"-1\n";
					return 0;
				}
				b_ = b-(a-f);
				count++;
				filled = true;
				if(b_<0){
					cout<<"-1\n";
					return 0;
				}
			}
			else{
				filled = false;
				b_ -= (a-f);
			}
			trip++;
		}
		else{
			if(b_-(a-f)<0){
				if(filled){
					cout<<"-1\n";
					return 0;
				}
				b_ = b - 2*(a-f);
				count++;
				if(b_<0){
					cout<<"-1\n";
					return 0;
				}
			}
			else{
				filled = false;
				b_ -= (a-f);
			}
			if(b_-f<0){
				if(filled){
					cout<<"-1\n";
					return 0;
				}
				b_ = b-f;
				count++;
				filled = true;
				if(b_<0){
					cout<<"-1\n";
					return 0;
				}
			}
			else{
				filled = false;
				b_ -= f;
			}
			trip++;
		}
	}
	cout<<count<<endl;

	return 0;
}