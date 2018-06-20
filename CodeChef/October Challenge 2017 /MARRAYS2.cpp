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

Int T,N,M,inp;
vi temp(1000009,0);
vi dp(1000009,0);

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>T;
	while(T--){
		cin>>N;
		vvi arr(N);
		fl(i,0,1000009)	dp[i] = 0;
		fl(i,0,N){
			cin>>M;
			fl(j,0,M){
				cin>>inp;
				arr[i].pb(inp);
			}
		}
		if(N==1){
			cout<<"0\n";
			continue;
		}
		Int min_index, minn, max_index, maxx, idx1, idx2;
		minn = 99999999, maxx = -1;
		//init
		fl(i,0,arr[1].size()){
			if(arr[1][i]<minn){
				minn = arr[1][i];
				min_index = i;
			}
			if(arr[1][i]>maxx){
				maxx = arr[1][i];
				max_index = i;
			}
		}
		maxx = -1;
		fl(i,0,arr[0].size()){
			if(abs(arr[0][i]-arr[1][min_index])>maxx){
				maxx = abs(arr[0][i]-arr[1][min_index]);
				idx1 = i;
			}
		}
		maxx = -1;
		fl(i,0,arr[0].size()){
			if(abs(arr[0][i]-arr[1][max_index])>maxx){
				maxx = abs(arr[0][i]-arr[1][max_index]);
				idx2 = i;
			}
		}
		fl(i,0,arr[1].size()){
			dp[i] = max(abs(arr[0][idx1]-arr[1][i]),abs(arr[0][idx2]-arr[1][i]));
		}
		//print
				// fl(i,0,2)	cout<<dp[i]<<" ";
				// cout<<endl;
		//-----
		fl(i,2,N){
			minn = 99999999, maxx = -1;
			vi max_index_arr, min_index_arr;
			fl(j,0,arr[i].size()){
				if(arr[i][j]<minn){
					minn = arr[i][j];
					min_index = j;
				}
				if(arr[i][j]>maxx){
					maxx = arr[i][j];
					max_index = j;
				}
			}
			maxx = -1;
			fl(j,0,arr[i-1].size()){
				if(dp[j]+abs(arr[i][min_index]-arr[i-1][(j+arr[i-1].size()-1)%arr[i-1].size()])*i>maxx){
					maxx = dp[j]+abs(arr[i][min_index]-arr[i-1][(j+arr[i-1].size()-1)%arr[i-1].size()])*i;
					idx1 = j;
				}
			}
			maxx = -1;
			fl(j,0,arr[i-1].size()){
				if(dp[j]+abs(arr[i][max_index]-arr[i-1][(j+arr[i-1].size()-1)%arr[i-1].size()])*i>maxx){
					maxx = dp[j]+abs(arr[i][max_index]-arr[i-1][(j+arr[i-1].size()-1)%arr[i-1].size()])*i;
					idx2 = j;
				}
			}
			fl(j,0,arr[i].size()){
				temp[j] = max( (dp[idx1]+abs(arr[i][j]-arr[i-1][(idx1+arr[i-1].size()-1)%arr[i-1].size()])*i),
						  		(dp[idx2]+abs(arr[i][j]-arr[i-1][(idx2+arr[i-1].size()-1)%arr[i-1].size()])*i));
			}
			fl(j,0,arr[i].size())	dp[j] = temp[j];
			//print
				// fl(i,0,arr[i].size())	cout<<dp[i]<<" ";
				// cout<<endl;
			//-----
		}
		maxx = -1;
		fl(i,0,arr[N-1].size()){
			if(dp[i]>maxx)	maxx = dp[i];
		}
		cout<<maxx<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}