//    VISHAL ANAND
#include <bits/stdc++.h>

using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
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
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}
/*ip
3 5
00100
10110
11001
*/

Int n,m,n1,m1;

int main(){
	ios;
	cin>>n>>m;
	n1 = (n%2);
	m1 = (m%2);
	Int arr[n+n1][m+m1];
	bool allOne=true;
	fl(i,0,n)
		fl(j,0,m){
			char ch;
			cin>>ch;
			arr[i][j]=ch-'0';
			if(arr[i][j]==0)	allOne=false;
		}
	if(allOne){
		cout<<"0\n";
		return 0;
	}
	if(m1){
		fl(i,0,n)	arr[i][m]=0;
	}
	if(n1){
		fl(i,0,m+m1)	arr[n][i]=0;
	}
	Int toggle=0,count[2];
	fl(i,0,(n+n1)/2){
		fl(j,0,(m+m1)/2){
			count[0]=count[1]=0;
			count[arr[2*i][2*j]]++;
			count[arr[2*i][2*j+1]]++;
			count[arr[2*i+1][2*j]]++;
			count[arr[2*i+1][2*j+1]]++;
			toggle += min(count[0],count[1]);
		}
	}
	cout<<toggle<<endl;

	return 0;
}