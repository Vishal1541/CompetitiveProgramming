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
5 3
1 2 3 4 5
1 1 2
2 3 4 -1
1 1 2
*/

Int N,Q,type,I,K,L,R,X;

int main(){
	ios;
	cin>>N>>Q;
	Int arr[N];
	fl(i,0,N)	cin>>arr[i];
	while(Q--){
		cin>>type;
		if(type==1){
			cin>>I>>K;
			I--;
			Int diff=0,fin=I+1,curr=I;
			while(K>0){
				if(I+1==N){
					break;
				}
				if(arr[I+1]>arr[curr]){
					diff++;
					if(diff>100)	break;
					K--;
					curr=I+1;
					I=curr;
					fin=curr+1;
					diff=0;
				}
				else if(arr[I+1]<=arr[curr]){
					diff++;
					I++;
				}
				else 	break;
			}
			cout<<fin<<endl;
		}
		else{
			cin>>L>>R>>X;
			L--;
			fl(i,L,R)	arr[i]+=X;
		}
	}

	return 0;
}