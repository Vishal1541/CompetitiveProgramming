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
#define MOD 1000000007
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

Int T,N;
string str;

int main(){
	ios;
	cin>>T;
	while(T--){
		cin>>str;
		N = str.length();
		vi flag(100,0), digits(10,0);
		Int num;
		fl(i,0,N)	digits[str[i]-'0']++;
		fl(i,0,10){
			fl(j,0,10){
				if(i!=j && digits[i] && digits[j]){
					num=i*10+j;
					if(num>=65 && num<=90)	flag[num]++;
					num=j*10+i;
					if(num>=65 && num<=90)	flag[num]++;
				}
			}
		}
		fl(i,0,10)
			if(digits[i]>=2 && i>=6 && i<=8)	flag[i*10+i]++;
		fl(i,65,91)
			if(flag[i])
				cout<<char(i);
		cout<<endl;
	}

	return 0;
}