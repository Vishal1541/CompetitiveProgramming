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
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int n,k;


int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n>>k;
	vvi arr(n, vi(k) );
	fl(i,0,n)	fl(j,0,k)	cin>>arr[i][j];
	bool yes = false;
	if(k==1){
		fl(i,0,n)
			if(arr[i][0]==0)	yes = true;
	}
	else if(k==2){
		bool c1 = false, c2 = false;
		fl(i,0,n){
			if(arr[i][0]==0)	c1 = true;
			if(arr[i][1]==0)	c2 = true;
		}
		if(c1==false || c2==false){
			cout<<"NO\n";
			return 0;
		}
		bool col1 = false, col2 = false;
		fl(i,0,n){
			if(arr[i][0]==0)	col1 = true;
			if(arr[i][1]==0)	col2 = true;
		}
		if(col1 && col2)	yes = true;
	}
	else if(k==3){
		bool c1 = false, c2 = false, c3 = false;
		fl(i,0,n){
			if(arr[i][0]==0)	c1 = true;
			if(arr[i][1]==0)	c2 = true;
			if(arr[i][2]==0)	c3 = true;
		}
		if(c1==false || c2==false || c3==false){
			cout<<"NO\n";
			return 0;
		}
		fl(i,0,n){
		int zero_cnt = 0;
			if(arr[i][0]==0)	zero_cnt++;
			if(arr[i][1]==0)	zero_cnt++;
			if(arr[i][2]==0)	zero_cnt++;
			if(zero_cnt==3){
				yes = true;
				break;
			}
			if(zero_cnt==2){
				int one_idx;
				if(arr[i][0]==1)	one_idx = 0;
				if(arr[i][1]==1)	one_idx = 1;
				if(arr[i][2]==1)	one_idx = 2;
				fl(j,0,n){
					if(arr[j][one_idx]==0){
						yes = true;
						break;
					}
				}
			}
			if(yes)	break;
		}
	}
	else if(k==4){
		vi four(4,0);
		bool c1 = false, c2 = false, c3 = false, c4 = false;
		fl(i,0,n){
			if(arr[i][0]==0)	c1 = true;
			if(arr[i][1]==0)	c2 = true;
			if(arr[i][2]==0)	c3 = true;
			if(arr[i][3]==0)	c4 = true;
		}
		if(c1==false || c2==false || c3==false || c4==false){
			cout<<"NO\n";
			return 0;
		}
		fl(i,0,n){
		int zero_cnt = 0;
			if(arr[i][0]==0)	zero_cnt++;
			if(arr[i][1]==0)	zero_cnt++;
			if(arr[i][2]==0)	zero_cnt++;
			if(arr[i][3]==0)	zero_cnt++;
			if(zero_cnt==4){
				yes = true;
				break;
			}
			if(zero_cnt==3){
				int one_idx;
				if(arr[i][0]==1)	one_idx = 0;
				if(arr[i][1]==1)	one_idx = 1;
				if(arr[i][2]==1)	one_idx = 2;
				if(arr[i][3]==1)	one_idx = 3;
				fl(j,0,n){
					if(arr[j][one_idx]==0){
						yes = true;
						break;
					}
				}
			}
			else if(zero_cnt==2){
				if(arr[i][0]==0)	four[0] = 1;
				if(arr[i][1]==0)	four[1] = 1;
				if(arr[i][2]==0)	four[2] = 1;
				if(arr[i][3]==0)	four[3] = 1;
			}
			if(four[0]==1 && four[1]==1 && four[2]==1 && four[3]==1)
				yes = true;
			if(yes)	break;		
		}
	}
	cout<<(yes?"YES\n":"NO\n");

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}