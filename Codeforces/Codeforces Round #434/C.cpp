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

string str;
vi vowelPos,alp(30,0);
si space;
si_it itr;
Int size=0,dist=0;

bool isVowel(char a){
	if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
		return true;
	return false;
}

int main(){
	ios;
	cin>>str;
	fl(j,0,30)	alp[j] = 0;
	fl(i,0,str.length()){
		if(isVowel(str[i])){
			dist = 0;
			size = 0;
			fl(j,0,30)	alp[j] = 0;
			continue;
		}
		size++;
		if(alp[str[i]-'a']==0){
			alp[str[i]-'a'] = 1;
			dist++;
		}
		if(dist>=2 && size>=3){
			space.insert(i-1);
			dist = 0;
			size = 0;
			fl(j,0,30)	alp[j] = 0;
			i--;
			continue;
		}
	}
	fl(i,0,str.length()){
		cout<<str[i];
		itr = space.find(i);
		if(itr!=space.end())
			cout<<" ";
	}
	cout<<endl;

	return 0;
}