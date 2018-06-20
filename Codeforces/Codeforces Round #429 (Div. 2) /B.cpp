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
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int n,oddCount=0,evenCount=0,ans=0;
vvi oddArr(2), evenArr(2);

int main(){
	ios;
	cin>>n;
	Int temp;
	fl(i,0,n){
		cin>>temp;
		if(temp%2){
			oddArr[0].pb(temp);
			oddArr[1].pb(0);
			oddCount++;
		}
		else{
			evenArr[0].pb(temp);
			evenArr[1].pb(0);
			evenCount++;
		}
	}
	int turn=1;
	while(1){
		if(oddCount==0){
			ans=2;
			break;
		}
		else if(evenCount==0){
			ans=1;
			break;
		}
		if(turn==1){
			if(oddCount%2){
				ans=1;
				break;
			}
			else{
				Int run=oddCount-1,lower=oddArr[0][0],upper=oddArr[0][oddArr[0].size()-1];
				oddCount=1;
				fl(i,0,oddArr[0].size()-1){
					oddArr[1][i]=1;
				}
				fl(i,0,evenArr[0].size()){
					if(evenArr[0][i]>lower && evenArr[0][i]<upper && evenArr[1][i]==0){
						evenArr[1][i]=1;
						evenCount--;
					}
				}
			}
			turn=2;
		}
		else{
			evenCount--;
		}
	}
	if(ans==1)	cout<<"First\n";
	else 		cout<<"Second\n";

	return 0;
}