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
3
5 2
1 6 5 0 3
3 1
0 3 0
4 2
3 4 3 5
*/
int T,N,D;

int main(){
	ios;
	cin>>T;
	while(T--){
		cin>>N>>D;
		Int arr[N], conv[N];
		Int TOTAL_SUM=0;
		fl(i,0,N){
			cin>>arr[i];
			TOTAL_SUM+=arr[i];
		}
		double avg = (double)TOTAL_SUM/N;
		if(avg != (Int)avg){
			cout<<"-1\n";
			continue;
		}
		Int moves=0;
		bool isPossible=true;
		fl(i,0,N-D){
			if(arr[i]<avg){
				moves+=avg-arr[i];
				arr[i+D]-=avg-arr[i];
				arr[i]+=avg-arr[i];
			}
			else if(arr[i]>avg){
				moves+=arr[i]-avg;
				arr[i+D]+=arr[i]-avg;
				arr[i]-=arr[i]-avg;
			}
		}
		fl(i,0,N){
			if(arr[i]!=avg){
				isPossible=false;
				//break;
			}
		}
		if(isPossible)	cout<<moves<<endl;
		else	cout<<"-1\n";
	}

	return 0;
}