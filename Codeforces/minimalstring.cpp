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

string s,s2,u;
string t="";

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	int s2_ptr = 0, t_length = 0;
	cin>>s;
	s2 = s;
	sort(s2);
	fl(i,0,s.length()){
		t[t_length] = s[i];
		t_length++;
		int j = t_length-1;
		while(j>=0){
			if(t[j]==s2[s2_ptr]){
				u = u+t[j];
				t_length--;
				j--;
				s2_ptr++;
			}
			
			else
				break;
		}
	}
	for(int i=t_length-1; i>=0; i--)	u = u+t[i];
	cout<<u<<endl;
cout<<__gcd(0,4)<<"...";

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}