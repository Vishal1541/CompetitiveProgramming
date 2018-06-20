//    VISHAL ANAND
/*ip
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/
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
// #define sort(v) sort(v.begin(),v.end());
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

Int T,N,Q,I,J,val;

bool comparefunc(const vi& arr1, const vi& arr2){
	return arr1[0]<arr2[0];
}

int main(){
	ios;
	cin>>T;
	while(T--){
		cin>>N>>Q;
		vi A(N,-1);
		bool ans = true;
		vvi queries(Q, vi(3) );
		fl(i,0,Q){
			cin>>I>>J>>val;
			I--,J--;
			queries[i][0] = min(I,J);
			queries[i][1] = max(I,J);
			queries[i][2] = val;
		}
		sort(queries.begin(),queries.end(),comparefunc);
		fl(i,0,Q){
			I = queries[i][0];
			J = queries[i][1];
			val = queries[i][2];
			if(I==J){
				if(val==1){
					ans = false;
					break;
				}
				continue;
			}
			if(A[I]==-1){
				// A[I] = val;
				// if(A[J] = -1){
				// 	A[J] = 0;
				// }
				if(A[J]==-1){
					A[I] = val;
					A[J] = 0;
				}
				else if(A[J]==0){
					A[I] = val;
				}
				else{
					if(val==1)	A[I] = 0;
					else 		A[I] = 1;
				}
			}
			else if(A[I]==val){
				if(A[J]==-1){
					A[J] = 0;
				}
				else if(A[J]==1){
					ans = false;
					break;
				}
			}
			else{
				if(A[I]==0 && val==1){
					if(A[J]==0){
						ans = false;
						break;
					}
					else{
						A[J] = 1;
					}
				}
				else if(A[I]==1 && val==0){
					if(A[J]==0){
						ans = false;
						break;
					}
					else{
						A[J] = 1;
					}
				}
			}
		}
		cout<<(ans?"yes\n":"no\n");
	}

	return 0;
}