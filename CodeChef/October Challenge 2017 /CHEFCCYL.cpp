//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
// #define vi vector<Int>
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

struct cycle{
	Int init_node, final_node;
};

Int T,N,Q,Ai,inp,v1,v2,w,c1,c2;
Int **dist_nodes, **segtree_nodes, *segtree_cycle, *segtree_forw, *segtree_back;

Int nextPowerOf2(Int n){
  Int count = 0;
  if (n && !(n&(n-1)))
    return n;
  while( n != 0){
    n  >>= 1;
    count += 1;
  }
  return 1 << count;
}

void constructSegTree(Int* inputArr, Int* segTreeArr, Int low, Int high, Int pos){
	if(low==high){
		segTreeArr[pos] = inputArr[low];
		return;
	}
	Int mid=(low+high)/2;
	constructSegTree(inputArr,segTreeArr,low,mid,2*pos+1);
	constructSegTree(inputArr,segTreeArr,mid+1,high,2*pos+2);
	segTreeArr[pos] = segTreeArr[2*pos+1]+segTreeArr[2*pos+2];
}

Int rangeQuery(Int segTreeArr[], Int qlow, Int qhigh, Int low, Int high, Int pos){
	if(qlow<=low && qhigh>=high)	return segTreeArr[pos];				//total overlap
	else if(qlow>high || qhigh<low)	return 0;	//no overlap
	Int mid=(low+high)/2;
	return max(rangeQuery(segTreeArr,qlow,qhigh,low,mid,2*pos+1),	//partial overlap
				rangeQuery(segTreeArr,qlow,qhigh,mid+1,high,2*pos+2));
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>T;
	while(T--){
		cin>>N>>Q;
		Int dist_forw[N], dist_back[N], Ai_store[N];
		segtree_cycle = new Int[nextPowerOf2(N)];
		segtree_forw = new Int[nextPowerOf2(N)];
		segtree_back = new Int[nextPowerOf2(N)];
		dist_nodes = new Int*[N];
		segtree_nodes = new Int*[N];
		cycle cycle_nodes[N];
		Int *cycle_weights = new Int[N];
		fl(i,0,N){
			cin>>Ai;
			Ai_store[i] = Ai;
			dist_nodes[i] = new Int[Ai];
			segtree_nodes[i] = new Int[nextPowerOf2(Ai)];
			fl(j,0,Ai){
				cin>>dist_nodes[i][j];
			}
			constructSegTree(dist_nodes[i],segtree_nodes[i],0,Ai-1,0);
		}
		fl(i,0,N){
			cin>>v1>>v2>>w;
			v1--,v2--;
			cycle_nodes[i].init_node = v1;
			cycle_nodes[i].final_node = v2;
			cycle_weights[i] = w;
		}
		constructSegTree(cycle_weights,segtree_cycle,0,N-1,0);
		//forward-dist
		fl(i,0,N){
			Int vi = cycle_nodes[(i+N-1)%Ai_store[i]].final_node;
			Int vf = cycle_nodes[i].init_node;
			if(vi<vf)
				dist_forw[i] = rangeQuery(segtree_nodes[i],vi,vf-1,0,Ai_store[i]-1,0);
			else if(vi>vf)
				dist_forw[i] = rangeQuery(segtree_nodes[i],0,Ai_store[i]-1,0,Ai_store[i]-1,0)
								-rangeQuery(segtree_nodes[i],vf,vi-1,0,Ai_store[i]-1,0);
			else
				dist_forw[i] = 0;
		}
		constructSegTree(dist_forw,segtree_forw,0,N-1,0);
		//backward-dist
		fl(i,0,N){
			Int vi = cycle_nodes[(i+N-1)%Ai_store[i]].final_node;
			Int vf = cycle_nodes[i].init_node;
			if(vi<vf)
				dist_back[i] = rangeQuery(segtree_nodes[i],0,Ai_store[i]-1,0,Ai_store[i]-1,0)
								-rangeQuery(segtree_nodes[i],vi,vf-1,0,Ai_store[i]-1,0);
			else if(vi>vf)
				dist_back[i] = rangeQuery(segtree_nodes[i],vf,vi-1,0,Ai_store[i]-1,0);
			else
				dist_back[i] = 0;
		}
		constructSegTree(dist_back,segtree_back,0,N-1,0);

		while(Q--){
			cin>>v1>>c1>>v2>>c2;
			v1--,c1--,v2--,c2--;
			if(c1>c2){
				swap(c1,c2);
				swap(v1,v2);
			}
			Int df, db;
			//dist-forw
			df = rangeQuery(segtree_cycle,c1,c2-1,0,N-1,0) + rangeQuery(segtree_forw,c1+1,c2-1,0,N-1,0);
			if(v1<cycle_nodes[c1].init_node){
				df += rangeQuery(segtree_nodes[c1],v1,cycle_nodes[c1].init_node-1,0,Ai_store[c1]-1,0);
			}
			else if(v1>cycle_nodes[c1].init_node){
				df += rangeQuery(segtree_nodes[c1],0,Ai_store[c1]-1,0,Ai_store[c1]-1,0)
								-rangeQuery(segtree_nodes[c1],cycle_nodes[c1].init_node,v1-1,0,Ai_store[c1]-1,0);
			}
			if(v2>cycle_nodes[(c2+N-1)%N].final_node){
				df += rangeQuery(segtree_nodes[c2],cycle_nodes[(c2+N-1)%N].final_node,v2-1,0,Ai_store[c2]-1,0);
			}
			else if(v2<cycle_nodes[(c2+N-1)%N].final_node){
				df += rangeQuery(segtree_nodes[c2],0,Ai_store[c2]-1,0,Ai_store[c2]-1,0)
						-rangeQuery(segtree_nodes[c2],v2,cycle_nodes[(c2+N-1)%N].final_node-1,0,Ai_store[c2]-1,0);
			}
			//dist-back
			db = rangeQuery(segtree_cycle,0,N-1,0,N-1,0)-rangeQuery(segtree_cycle,c1,c2-1,0,N-1,0);
			db += rangeQuery(segtree_back,0,c1-1,0,N-1,0) + rangeQuery(segtree_back,c2+1,N-1,0,N-1,0);
			if(v1<cycle_nodes[(c1+N-1)%N].final_node){
				db += rangeQuery(segtree_nodes[c1],v1,cycle_nodes[(c1+N-1)%N].final_node-1,0,Ai_store[c1]-1,0);
			}
			else if(v1>cycle_nodes[(c1+N-1)%N].final_node){
				db += rangeQuery(segtree_nodes[c1],0,Ai_store[c1]-1,0,Ai_store[c1]-1,0)
						-rangeQuery(segtree_nodes[c1],cycle_nodes[(c1+N-1)%N].final_node,v1-1,0,Ai_store[c1]-1,0);
			}
			cout<<db<<" ";
			if(v2>cycle_nodes[c2].init_node){
				db += rangeQuery(segtree_nodes[c2],cycle_nodes[c2].init_node,v2-1,0,Ai_store[c2]-1,0);
			}
			else if(v2<cycle_nodes[c2].init_node){
				db += rangeQuery(segtree_nodes[c2],0,Ai_store[c2]-1,0,Ai_store[c2]-1,0)
						-rangeQuery(segtree_nodes[c2],v2,cycle_nodes[c2].init_node-1,0,Ai_store[c2]-1,0);
			}
			cout<<min(df,db)<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}