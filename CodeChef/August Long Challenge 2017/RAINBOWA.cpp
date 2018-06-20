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
19
1 2 3 4 4 5 6 6 6 7 6 6 6 5 4 4 3 2 1
14
1 2 3 4 5 6 7 6 5 4 3 2 1 1
13
1 2 3 4 5 6 8 6 5 4 3 2 1
*/
Int T,N;

int main(){
	ios;
	cin>>T;
	while(T--){
		mii seq;
		mii :: iterator itr;
		fl(i,0,7)	seq[i+1]=0;
		cin>>N;
		int arr[N];
		fl(i,0,N)	cin>>arr[i];
		int ptr=1;
		bool isPossible=true;
		fl(i,0,N){
			if(N-i-1<i)	break;
			if(arr[i]==arr[N-i-1] && arr[i]==ptr){
				seq[arr[i]]=1;
			}
			else if(arr[i]==arr[N-i-1] && arr[i]==ptr+1){
				seq[arr[i]]=1;
				ptr++;
			}
			else {
				isPossible=false;
				break;
			}
		}
		if(isPossible)
			foreach(itr,seq)
				if(itr->S == 0){
					isPossible=false;
					break;
				}
		if(isPossible)	cout<<"yes\n";
		else 	cout<<"no\n";
	}

	return 0;
}