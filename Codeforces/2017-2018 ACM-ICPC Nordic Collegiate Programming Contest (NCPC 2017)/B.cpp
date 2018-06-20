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

Int n,m,t,p,Rank=1;
mii ques_teams;
map<int, pair<int,int> > team_ques;
set<pair<int,int> > penalty[100000+9];
mii counter[100000+5];
set<pair<int,int> > :: iterator itr;
set<pair<int,int> > :: iterator itr2;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n>>m;
	// int a = itr->S;
	fl(i,0,m){
		cin>>t>>p;
		// ques_teams[team_ques[t].F]--;
		itr = penalty[team_ques[t].F].find(make_pair(team_ques[t].S,counter[team_ques[t].F][team_ques[t].S]) );
		if(counter[team_ques[t].F][team_ques[t].S]!=0){
			int a = itr->F;
			int b = itr->S;
			penalty[team_ques[t].F].erase(itr);
			penalty[team_ques[t].F].insert(make_pair(a,b-1));
			counter[team_ques[t].F][team_ques[t].S]--;
			if(itr->S<=0){
				penalty[team_ques[t].F].erase(itr);
				counter[team_ques[t].F][team_ques[t].S] = 0;
			}
		}

		if(t!=1){
			if((team_ques[t].F+1)==team_ques[1].F && (team_ques[t].S+p)<team_ques[1].S){
				Rank++;
			}
			else if(team_ques[t].F==team_ques[1].F){
				Rank++;
			}
		}
		else{
			int l = 0, h = penalty[1].size()-1;
			int m = (l+h)/2;
			while(l<=h){
				m = (l+h)/2;
				itr = penalty[1].begin();
				advance(itr,m);
				if(itr->F==team_ques[1].S){
					// Rank -= (m-l);
					break;
				}
				if(itr->F>team_ques[1].S){
					h = m-1;
				}
				else if(itr->F<team_ques[1].S){
					l = m+1;
				}
				// cout<<l<<h<<" ";
			}
			for(itr2=penalty[1].begin(); itr2!=itr; itr2++)	Rank -=  itr2->S;
		}
		team_ques[t].F++;
		team_ques[t].S += p;



		itr = penalty[team_ques[t].F].find(make_pair(team_ques[t].S,counter[team_ques[t].F][team_ques[t].S]));
		if(counter[team_ques[t].F][team_ques[t].S]==0){
			penalty[team_ques[t].F].insert(make_pair(team_ques[t].S,1));
			counter[team_ques[t].F][team_ques[t].S] = 1;
		}
		else{
			itr2 = penalty[team_ques[t].F].find(make_pair(team_ques[t].S,counter[team_ques[t].F][team_ques[t].S]));
			int a = itr2->F;
			int b = itr2->S;
			penalty[team_ques[t].F].erase(itr2);
			penalty[team_ques[t].F].insert(make_pair(a,b+1));
			counter[team_ques[t].F][team_ques[t].S]++;
		}
		if(t==1){
			int l = 0, h = penalty[1].size()-1;
			int m = (l+h)/2;
			while(l<=h){
				m = (l+h)/2;
				itr = penalty[1].begin();
				advance(itr,m);
				if(itr->F==team_ques[1].S){
					// Rank -= (h-m);
					break;
				}
				if(itr->F>team_ques[1].S){
					h = m-1;
				}
				else if(itr->F<team_ques[1].S){
					l = m+1;
				}
			}
			itr++;
			for(itr2=itr; itr2!=penalty[1].end(); itr2++)	Rank -= itr2->S;
		}
		cout<<Rank<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}