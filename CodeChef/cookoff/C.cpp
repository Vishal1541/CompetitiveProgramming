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
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int T,N;

struct Chess{
	int R, Min, Max,timee;
	string Color,isRated;
};

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>T;
	while(T--){
		cin>>N;
		Chess chess[N];
		vi flag(N,0);
		string ans[N];
		fl(i,0,N){
			cin>>chess[i].R>>chess[i].Min>>chess[i].Max>>chess[i].timee>>chess[i].isRated>>chess[i].Color;
		}
		bool yes = false;
		fl(i,0,N){
			yes = false;
				fl(j,0,i){
					if(chess[j].R>=chess[i].Min && chess[j].R<=chess[i].Max
						&& chess[i].R>=chess[j].Min && chess[i].R<=chess[j].Max
						&& chess[i].timee==chess[j].timee
					&& chess[i].isRated.compare(chess[j].isRated)==0
					&& !flag[j] && !flag[i]){
						if( (chess[i].Color.compare("random")==0 &&
							chess[j].Color.compare("random")==0 ) 
							||
							(chess[i].Color.compare("white")==0 &&
							chess[j].Color.compare("black")==0 ) 
							||
							(chess[i].Color.compare("black")==0 &&
							chess[j].Color.compare("white")==0 ) 
							){
								flag[i] = flag[j] = 1;
								cout<<j+1<<endl;
								yes = true;
								break;
							}
					}
				}
			if(!yes){
				cout<<"wait\n";
			}
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}