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

Int ax,ay,bx,by,cx,cy;
Int d1,d2,dx1,dx2;
long double m1,m2;

int main(){
	ios;
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	d1 = (by-ay)*(by-ay) + (bx-ax)*(bx-ax);
	d2 = (cy-by)*(cy-by) + (cx-bx)*(cx-bx);
	dx1 = (bx-ax);
	dx2 = (cx-bx);
	if(dx1 == 0 && dx2 == 0){
		cout<<"NO\n";
		return 0;
	}
	if( (dx1==0 && dx2!=0) || (dx1==0 && dx2!=0) ){
		if(d1==d2){
			cout<<"YES\n";
		}
		else
			cout<<"NO\n";
		return 0;
	}
	m1 = ((double)(by-ay)/(bx-ax));
	m2 = ((double)(cy-by)/(cx-bx));

	cout<<((m1!=m2 && d1==d2)?"YES\n":"NO\n");

	return 0;
}