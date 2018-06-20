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
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

/*
25-21 2
20 16 3
15 11 4
10 1 5
*/

string s;
int cons_wins = 0, stars = 0, Rank = 25;
bool bonus_star;
vi Rank_star(30);

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	fl(i,21,26)	Rank_star[i] = 2;
	fl(i,16,21)	Rank_star[i] = 3;
	fl(i,11,16)	Rank_star[i] = 4;
	fl(i,1,11)	Rank_star[i] = 5;

	cin>>s;
	fl(i,0,s.length()){
		if(s[i]=='W'){
			bonus_star = false;
			if(s[i]=='W'){
				cons_wins++;
				stars++;
			}
			if(cons_wins>=3 && Rank>=6 && Rank<=25){
				stars++;
				bonus_star = true;
			}
			if(stars-Rank_star[Rank]==1){
				Rank--;
				stars = 1;
			}
			else if(stars-Rank_star[Rank]==2){
				Rank--;
				stars = 2;
			}
		}
		else{
			cons_wins = 0;
			if(Rank>20)	continue;
			if(stars==0 && Rank==20)	continue;
			stars--;
			if(stars<0){
				Rank++;
				stars = Rank_star[Rank]-1;
			}
		}
		if(Rank==0)	break;
	}
	if(Rank==0)	cout<<"Legend\n";
	else 	cout<<Rank<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}