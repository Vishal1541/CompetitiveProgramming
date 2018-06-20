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

bool isAlpha(char a){
	return ((a>='A' && a<='Z') || (a>='a' && a<='z'));
}

bool isUpper(char a){
	return (a>='A' && a<='Z');
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	int T,L,Q;
	cin>>T;
	while(T--){
		string decoded,encoded;
		cin>>decoded>>encoded>>L;
		int key[L],pt = 0;
		fl(i,0,encoded.length()){
			if(isAlpha(encoded[i])){
				int diff = decoded[i] - encoded[i];
				if(diff<0)	diff += 26;
				key[pt++] = diff;
			}
			if(pt==L)	break;
		}
		cin>>Q;
		cin.ignore();
		while(Q--){
			string s;
			pt = 0;
			getline(cin,s);
			fl(i,0,s.length()){
				if(isAlpha(s[i])){
					if(isUpper(s[i])){
						int f = s[i]+key[pt++];
						if(f>90)	f = key[pt-1]-(90-s[i])+65-1;
						cout<<(char)f;
					}
					else{
						int f = s[i]+key[pt++];
						if(f>122)	f = key[pt-1]-(122-s[i])+97-1;
						cout<<(char)f;
					}
				}
				else{
					cout<<s[i];
				}
				if(pt==L)	pt = 0;
			}
			cout<<endl;
		}
	}

	return 0;
}