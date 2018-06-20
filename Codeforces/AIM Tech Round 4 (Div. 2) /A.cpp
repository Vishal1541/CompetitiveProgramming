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
#define us unordered_set
#define um unordered_map
#define mii map<Int,Int>
#define qi queue<Int>
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define PI 3.141592653589793238L
#define F first
#define S second
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define mp make_pair
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

string s;
int k,already_diff=0,occupied=0,change=0;
vi already_same;

int main(){
	ios;
	cin>>s>>k;
	bool isPossible = false;
	vi arr(100,0);
	fl(i,0,s.length())	arr[s[i]-'a']++;
	fl(i,0,26){
		if(arr[i]==1)		already_diff++;
		else if(arr[i]>1)	already_same.pb(arr[i]);
		if(arr[i]>=1)		occupied++;
	}
	fl(i,0,already_same.size()){
		if(occupied>=k && occupied<=26){
			isPossible = true;
			break;
		}
		while(already_same[i]!=1){
			already_same[i]--;
			occupied++;
			change++;
			if(occupied>=k && occupied<=26){
				isPossible = true;
				break;
			}
		}
	}
	if(occupied>=k && occupied<=26)	isPossible = true;
	if(isPossible)	cout<<change<<endl;
	else 			cout<<"impossible\n";

	return 0;
}