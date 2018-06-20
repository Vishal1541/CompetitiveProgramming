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

int L,C;
vvi arr(320,vi(320) );
vi pos(320,0), row_pos(320,0);


int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>L>>C;
	bool isPossible = true;
	fl(i,1,L+1)	fl(j,1,C+1)	cin>>arr[i][j];
	int row = ceil((double)arr[1][1]/C);
	fl(i,1,C+1){
		pos[i] = arr[1][i] - C*(row-1);
	}
	fl(i,2,L+1){
		row = ceil((double)arr[i][1]/C);
		fl(j,1,C+1){
			if(pos[j] != (arr[i][j] - C*(row-1)) ){
				isPossible =false;
				break;
			}
		}
	}
	if(!isPossible){
		cout<<"*\n";
		return 0;
	}
	int row_swapped= 0, col_swapped = 0;
	fl(i,1,L+1){
		row = ceil((double)arr[i][1]/C);
		row_pos[i] = row;
	}
	fl(i,1,C+1){
		if(pos[i]!=i){
			swap(pos[i],pos[pos[i]]);
			i--;
			col_swapped++;
		}
	}
	fl(i,1,L+1){
		if(row_pos[i]!=i){
			swap(row_pos[i],row_pos[row_pos[i]]);
			i--;
			row_swapped++;
		}
	}
	cout<<(row_swapped+col_swapped)<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}