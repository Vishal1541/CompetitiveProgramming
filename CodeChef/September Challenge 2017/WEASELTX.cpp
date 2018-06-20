//    VISHAL ANAND
/*ip
4 3
0 1
1 2
0 3
1 5 8 7
1
2
3
*/
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define pb push_back

Int N,Q,X,d,u,v,heightOfTree=0;


// struct Pair{
// 	Int node,height;
// };

// Int nextPowerOf2(Int  n){
//   Int count = 0;
//   if (n && !(n&(n-1)))
//     return n;
//   while( n != 0){
//     n  >>= 1;
//     count += 1;
//   }
//   return 1 << count;
// }

// bool cmpfunc(Pair A,Pair B){
// 	return A.height<B.height;
// }

void findDepth(vvi& adjlist, vi& visited, Int node, Int h, vi& parentOf,vi& depth){
	visited[node] = 1;
	depth[node] = h;
	// p[node].height = h;
	if(h>heightOfTree)	heightOfTree = h;
	fl(i,0,adjlist[node].size()){
		if(!visited[adjlist[node][i]]){
			parentOf[adjlist[node][i]] = node;
			findDepth(adjlist,visited,adjlist[node][i],h+1,parentOf,depth);
		}
	}
}

Int updateXor(Int node, vvi& adjlist, vi& Xor, vi& depth,vvi& dp2, Int day,vi& parentOf,vi& repeat){
	fl(i,0,adjlist[node].size()){
		 if(adjlist[node][i] != parentOf[node]){
			if(dp2[adjlist[node][i]].size()<repeat[adjlist[node][i]]){
				Xor[node] ^= updateXor(adjlist[node][i],adjlist,Xor,depth,dp2,day,parentOf,repeat);
			}
			else{
				Xor[node] ^= dp2[adjlist[node][i]][day%repeat[adjlist[node][i]]];
			}
		 }
	}
	dp2[node].pb(Xor[node]);
	return Xor[node];
}

int main(){
	ios;
	cin>>N>>Q;
	// Int dp[N+2][2*N+2]={-1}; //N-d
	vi parentOf(N+2,-1);
	vi Xor(N),visited(N,0),depth(N),repeat(N);
	vvi adjlist(N), dp2(N);
	// Pair p_ini[N],p[N];
	// fl(i,0,N){
	// 	p_ini[i].node = i;
	// 	p_ini[i].height = 0;
	// }
	fl(i,0,N-1){
		cin>>u>>v;
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	findDepth(adjlist,visited,0,0,parentOf,depth);
	// fl(i,0,N){
	// 	p[i] = p_ini[i];
	// }
	// sort(p,p+N,cmpfunc);
	// heightOfTree = p[N-1].height+1;
	heightOfTree++;
	heightOfTree = 1<<(Int)ceil(log2(heightOfTree));
	fl(i,0,N){
		cin>>Xor[i];
		dp2[i].pb(Xor[i]);
		repeat[i] = 1<<(Int)ceil(log2(heightOfTree - depth[i]));
	}
	// fl(i,1,N){
	// 	repeat[i] = heightOfTree - depth[i];
	// 	repeat[i] = (Int)ceil(log2(repeat[i]));
	// 	repeat[i] = 1<<repeat[i];
	// }
	// tempXor = Xor;
	vi dp(heightOfTree+2,0);
	dp[0] = Xor[0];
	fl(i,1,heightOfTree){
		dp[i] = updateXor(0,adjlist,Xor,depth,dp2,i,parentOf,repeat);
	}
	while(Q--){
		cin>>d;
		d %= heightOfTree;
		cout<<dp[d]<<endl;
	}

	return 0;
}