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

Int n,m,node=0,ans=0;
char inp;

bool isValid(Int i, Int j){
	return (i>=0 && i<n && j>=0 && j<m);
}

void traverse(vector<vector<char> >& arr, Int i, Int j, vi& visited){
	if(isValid(i,j)){
		if(!visited[i*m+j] && arr[i][j]!='W'){
			visited[i*m+j] = 1;
			traverse(arr, i, j+1, visited);
			traverse(arr, i, j-1, visited);
			traverse(arr, i+1, j, visited);
			traverse(arr, i-1, j, visited);
		}
	}
}

int main(){
	ios;
	cin>>n>>m;
	vector<vector<char> > arr(n);
	vi visited(n*m+5,0);
	vvi tree(n*m+5);

	fl(i,0,n)fl(j,0,m){
		cin>>inp;
		arr[i].pb(inp);
	}

	fl(i,0,n){
		fl(j,0,m){
			if(arr[i][j]=='L' && !visited[i*m+j]){
				ans++;
				traverse(arr,i,j,visited);
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}