//    VISHAL ANAND
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <functional>

using namespace std;

#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define us unordered_set
#define um unordered_map
#define mm multimap
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

int T,N,K,P,ing;
mm<int,vi,greater<int> > :: iterator itr;

int main(){
	cin>>T;
	while(T--){
		mm<int,vi,greater<int> >m;
		cin>>N>>K;
		vi visited(K+1,0);
		int found = 0, island_vis = 0;
		fl(i,0,N){
			vi v_temp;
			cin>>P;
			fl(j,0,P){
				cin>>ing;
				v_temp.pb(ing);
			}
			m.insert(make_pair(P,v_temp));
		}
		bool inside_loop;
		foreach(itr,m){
			inside_loop = false;
			fl(i,0,itr->F){
				ing = itr->S[i];
				if(!visited[ing]){
					visited[ing] = 1;
					found++;
					inside_loop = true;
				}
			}
			if(inside_loop)
				island_vis++;
		}
		if(found!=K)	cout<<"sad\n";
		else if(island_vis!=N)	cout<<"some\n";
		else	cout<<"all\n";
	}

	return 0;
}