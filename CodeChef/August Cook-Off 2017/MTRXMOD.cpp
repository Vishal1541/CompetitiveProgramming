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

Int N,Q,p;

void process(vvi &arr, vi &A, vi &negative, vi &flag){
	fl(i,1,N){
		fl(j,1,N){
			if(i!=j && !(flag[i] && flag[j])){
				if(arr[i][j]==abs( A[i]-A[j]) ){
					if(!flag[i] && !flag[j]){
						negative[i] = negative[j] = 1;
					}
					else if(flag[i] && negative[i])
						flag[j] = negative[j] = 1;
					else if(flag[j] && negative[j])
						flag[i] = negative[i] = 1;
				}
				else{
					if(!flag[i] && !flag[j])
						negative[i] = 1;
					if(!flag[i] && flag[j] && !negative[j])
						negative[i] = 1;
					else if(flag[i] && !flag[j] && !negative[i])
						negative[j] = 1;
				}
				flag[i] = flag[j] = 1;
			}
		}
	}
}

int main(){
	ios;
	cin>>N>>Q;
	vvi arr(N, vi(N) );
	fl(i,0,N)	fl(j,0,N)	cin>>arr[i][j];
	vi A(N,0),negative(N,0),flag(N,0);
	fl(i,1,N)	A[i] = arr[0][i];
	process(arr,A,negative,flag);
	fl(i,0,N){
		if(negative[i])	cout<<"-";
		cout<<A[i]<<" ";
	}
	cout<<endl;
	while(Q--){
		cin>>p;
		p--;
		vi F(N);
		fl(i,0,N)	cin>>F[i];
		fl(i,0,N){
			arr[i][p] = arr[p][i] = F[i];
		}
		fl(i,1,N)	A[i] = arr[0][i];
		vi negative2(N,0), flag2(N,0);
		process(arr,A,negative2,flag2);
		fl(i,0,N){
			if(negative2[i])	cout<<"-";
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}