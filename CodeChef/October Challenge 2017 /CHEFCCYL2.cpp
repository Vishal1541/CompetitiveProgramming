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

Int T,N,Q,Ai,v1,v2,w,c1,c2,inp;

struct cycle{
	int init_node, final_node;
};

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>T;
	while(T--){
		cin>>N>>Q;
		vi cycle_weights(N+1,0),Ai_store(N+1,0),cw_nodes(N+1,0),ccw_nodes(N+1,0);
		vvi dist_nodes(N+1);
		fl(i,1,N+1)	dist_nodes[i].pb(0);
		cycle cycle_nodes[N+1];
		fl(i,1,N+1){
			cin>>Ai;
			Ai_store[i] = Ai;
			fl(j,1,Ai+1){
				cin>>inp;
				dist_nodes[i].pb(dist_nodes[i][j-1]+inp);
			}
		}
		fl(i,1,N+1){
			cin>>v1>>v2>>w;
			cycle_weights[i] = cycle_weights[i-1]+w;
			cycle_nodes[i].init_node = v1;
			cycle_nodes[i].final_node = v2;

		}	
		fl(i,1,N+1){
			int Vi, Vf;
			//CW
			Vi = cycle_nodes[(i-1+N-1)%N+1].final_node;	
			Vf = cycle_nodes[i].init_node;
			if(Vi<Vf){
				cw_nodes[i] = min(cw_nodes[i-1]+dist_nodes[i][Vf-1]-dist_nodes[i][Vi-1],
						cw_nodes[i-1]+dist_nodes[i][Ai_store[i]]-(dist_nodes[i][Vf-1]-dist_nodes[i][Vi-1]));
			}
			else if(Vi>Vf){
				cw_nodes[i] = min(cw_nodes[i-1]+dist_nodes[i][Vi-1]-dist_nodes[i][Vf-1],
						cw_nodes[i-1]+dist_nodes[i][Ai_store[i]]-(dist_nodes[i][Vi-1]-dist_nodes[i][Vf-1]));
			}
			else{
				cw_nodes[i] = cw_nodes[i-1];
			}
		}
		while(Q--){
			cin>>v1>>c1>>v2>>c2;
			int Vi, Vf;
			Int a=0,c=0; 
			if(c1>c2){
				swap(v1,v2);
				swap(c1,c2);
			}
			Vi = cycle_nodes[c1].init_node;
			Vf = cycle_nodes[(c2-1+N-1)%N+1].final_node;
			//cycle-right
			if(v1<Vi){
				a += min(dist_nodes[c1][Vi-1]-dist_nodes[c1][v1-1],
						dist_nodes[c1][Ai_store[c1]]-(dist_nodes[c1][Vi-1]-dist_nodes[c1][v1-1]));
			}
			else if(v1>Vi){
				a += min(dist_nodes[c1][v1-1]-dist_nodes[c1][Vi-1],
						dist_nodes[c1][Ai_store[c1]]-(dist_nodes[c1][v1-1]-dist_nodes[c1][Vi-1]));
			}
			a += cycle_weights[c2-1]-cycle_weights[c1-1];
			a += cw_nodes[c2-1]-cw_nodes[c1];
			if(v2<Vf){
				a += min(dist_nodes[c2][Ai_store[c2]]-(dist_nodes[c2][Vf-1]-dist_nodes[c2][v2-1]),	
						dist_nodes[c2][Vf-1]-dist_nodes[c2][v2-1]);
			}
			else if(v2>Vf){
				a += min(dist_nodes[c2][Ai_store[c2]]-(dist_nodes[c2][v2-1]-dist_nodes[c2][Vf-1]),	
						dist_nodes[c2][v2-1]-dist_nodes[c2][Vf-1]);
			}
			
			//cycle-left
			Vf = cycle_nodes[c2].init_node;
			Vi = cycle_nodes[(c1-1+N-1)%N+1].final_node;
			if(v1<Vi){
				c += min(dist_nodes[c1][Ai_store[c1]]-(dist_nodes[c1][Vi-1]-dist_nodes[c1][v1-1]),
						(dist_nodes[c1][Vi-1]-dist_nodes[c1][v1-1]));
			}
			else if(v1>Vi){
				c += min(dist_nodes[c1][Ai_store[c1]]-(dist_nodes[c1][v1-1]-dist_nodes[c1][Vi-1]),
						(dist_nodes[c1][v1-1]-dist_nodes[c1][Vi-1]));
			}
			c += cycle_weights[N]-(cycle_weights[c2-1]-cycle_weights[c1-1]);
			c += cw_nodes[N]-(cw_nodes[c2]-cw_nodes[c1-1]);
			if(v2<Vf){
				c += min(dist_nodes[c2][Vf-1]-dist_nodes[c2][v2-1],	
						dist_nodes[c2][Ai_store[c2]]-(dist_nodes[c2][Vf-1]-dist_nodes[c2][v2-1]));
			}
			else if(v2>Vf){
				c += min(dist_nodes[c2][v2-1]-dist_nodes[c2][Vf-1],	
						dist_nodes[c2][Ai_store[c2]]-(dist_nodes[c2][v2-1]-dist_nodes[c2][Vf-1]));
			}
			cout<<min(a,c)<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}