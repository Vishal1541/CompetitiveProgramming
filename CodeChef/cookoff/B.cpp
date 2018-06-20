//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int T,N,M;
int flag[1009][1009];

struct Snow{
	int height,i,j;
};

bool cmp(const Snow& a, const Snow& b){
	return a.height>b.height;
}

Snow make_snow(int h, int i, int j){
	Snow s = {h,i,j};
	return s;
}

bool isValid(int i, int j){
	return (i>=0 && i<N && j>=0 && j<M);
}

void solve(auto& arr,auto& visi, auto& counted, int i, int j,auto& flag,int last){
	if(flag[i][j])	return;
	flag[i][j] = 1;
		if(visi[make_pair(i,j)]==1){
			visi[make_pair(i,j)] = 0;
			counted--;
		}
		if(isValid(i-1,j) && arr[i-1][j]<=last)
		solve(arr,visi,counted,i-1,j,flag,arr[i-1][j]);
		if(isValid(i+1,j) && arr[i+1][j]<=last)
		solve(arr,visi,counted,i+1,j,flag,arr[i+1][j]);

		if(isValid(i,j-1) && arr[i][j-1]<=last)
		solve(arr,visi,counted,i,j-1,flag,arr[i][j-1]);

		if(isValid(i,j+1) && arr[i][j+1]<=last)
		solve(arr,visi,counted,i,j+1,flag,arr[i][j+1]);
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>T;
	while(T--){
		cin>>N>>M;
		vvi arr(N,vi(M) ), flag(N,vi(M) );
		vector<Snow> snow,ins;
		map<pair<int,int>,int >visi;
		fl(i,0,N)fl(j,0,M){
			cin>>arr[i][j];
			snow.pb(make_snow(arr[i][j],i,j));
			flag[i][j] = 0;
			visi[make_pair(i,j)] = 1;
		}
		Int counted = N*M;
		sort(snow.begin(), snow.end(), cmp);
		// fl(i,0,N*M)	cout<<snow[i].height<<snow[i].i<<snow[i].j<<" ";
		int idx = 0;
		Int ans=0;
			vvi flagg(N,vi(M));
			fl(k,0,N)fl(l,0,M)flagg[k][l] = 0;
		while(counted>0){
			int ii = snow[idx].i;
			int jj = snow[idx].j;
			if(!flagg[ii][jj]){
				solve(arr,visi,counted,ii,jj,flagg,snow[idx].height);
				// cout<<snow[idx].height<<"..";
				ans++;
			}
				idx++;
		}		
		cout<<ans<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}