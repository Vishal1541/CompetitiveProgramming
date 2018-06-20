//    VISHAL ANAND
/*ip
5 6
1 2 3 4 1
3 4 1 2 1 3
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

Int n,m,arr[110][110],ar1[110],ar2[110],ans[110];

void fillSeq(int len, int i, int j){
	if(len!=0){
		if(ar1[j-1]==ar2[i-1]){
			cout<<i<<j<<"..";
			ans[--len] = ar1[j-1];
			fillSeq(len,i-1,j-1);
		}
		else
			fillSeq(len,i,j-1);
	}
}

int main(){
	ios;
	fl(i,0,110)	arr[i][0] = arr[0][i] = 0;
	cin>>n>>m;
	fl(i,0,n)	cin>>ar1[i];
	fl(i,0,m)	cin>>ar2[i];

	fl(i,1,m+1){
		fl(j,1,n+1){
			if(ar1[j-1]==ar2[i-1])	arr[i][j] = 1+arr[i-1][j-1];
			else 	arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
		}
	}
	fillSeq(arr[m][n],m,n);
	fl(i,0,arr[m][n])	cout<<ans[i]<<" ";

	return 0;
}