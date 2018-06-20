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

string String(char a){
	if(a=='0')	return "0";
	if(a=='1')	return "1";
	if(a=='2')	return "2";
	if(a=='3')	return "3";
	if(a=='4')	return "4";
	if(a=='5')	return "5";
	if(a=='6')	return "6";
	if(a=='7')	return "7";
	if(a=='8')	return "8";
	if(a=='9')	return "9";
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>t;
	while(t--){
		cin>>s;
		vector<string> ss,sumarr(s.length()),sumarr2(s.length());
		int sumall = 0, last = s.length()-1, idx=-1;
		fl(i,0,s.length())	sumall += (s[i]-'0');
		if((s[last]-'0')%2==0){
			fl(i,0,last){
				if((sumall-(s[i]-'0'))%3==0 && (s[i+1]-'0')>(s[i]-'0')){
					idx = i;
					break;
				}
			}
		}
		if( (s[last-1]-'0')%2==0 && (sumall-(s[last]-'0'))%3==0){
			if(idx==-1)	idx = last;
		}
		if(idx==-1){
			if((s[last]-'0')%2==0){
				for(int i=last-1; i>=0; i--){
					if((sumall-(s[i]-'0'))%3==0){
						idx = i;
						break;
					}
				}
			}
		}
		if(idx==-1){
			cout<<"-1\n";
		}
		else{
			fl(i,0,last+1){
				if(i!=idx)	cout<<s[i];
			}
			cout<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}