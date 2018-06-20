//    VISHAL ANAND
/*
3
5 5
1 1 2
1 4 5
2 1 2
2 1 3
2 3 4
1 2
1 1 1
1 1 1
10 10
1 1 10
2 1 1
2 1 2
2 1 3
2 1 4
2 1 5
2 1 6
2 1 7
2 1 8
2 1 9
*/
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
#define us unordered_set
#define um unordered_map
#define mii map<Int,Int>
#define qi queue<Int>
#define pb push_back
#define MOD 1000000007
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
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int T,n,m,type,L,R,size,mod=1000000007;
map<Int,Int>  :: iterator itr;

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


void updateRange(vi& tree,Int node, Int start, Int end, Int l, Int r, Int val){
    if (start > end || start > r || end < l)
        return;

    if (start == end){
        tree[node] = (tree[node]%mod + val%mod)%mod;
        // cout<<tree[node]<<"-"<<node<<"   ";
        return;
    }

    Int mid = (start + end) / 2;
    updateRange(tree, node*2+1, start, mid, l, r, val);
    updateRange(tree, node*2+2, mid + 1, end, l, r, val);

    if( (tree[node*2+1] == tree[node*2+2]) && tree[node*2+1]>=0 && tree[node*2+2]>=0)
    	tree[node] = tree[node*2+1];
    else
    	tree[node] = -1;
}

void solveCalls(auto& queries,Int i,auto& counts, bool add,Int idx){
	if(queries[i][0]==1){
		queries[i][3] = (queries[i][3]+1)%mod;
		if(add)	counts[idx][i] = (counts[idx][i]+1)%mod;
	}
	else if(queries[i][0]==2 && queries[i][4]==0){
		queries[i][4]=1;
		fl(j,queries[i][1],queries[i][2]+1)	solveCalls(queries,j,counts,true,i);
	}
	else if(queries[i][0]==2 && queries[i][4]==1){
		for(itr=counts[i].begin(); itr!=counts[i].end(); itr++){
			counts[idx][itr->F] = (counts[idx][itr->F]+counts[i][itr->F])%mod;
			queries[itr->F][3] = (queries[itr->F][3]+itr->S)%mod;
			// cout<<i<<itr->F<<itr->S<<"...";
		}
	}
}

void fillArrayfromTree(vi& A, vi& tree,Int node, Int start, Int end){
	if(start==end){
		A[start] = tree[node];
		return;
	}
	int mid = (start + end) / 2;
    fillArrayfromTree(A, tree, node*2+1, start, mid);
    fillArrayfromTree(A, tree, node*2+2, mid + 1, end);
}

int main(){
	ios;
	cin>>T;
	while(T--){
		cin>>n>>m;
		vector<map<Int,Int> > counts(m);
		Int x = (Int)(ceil(log2(n)));
		Int size = 2*(Int)pow(2, x) - 1;
		vi A(n),tree(size,0);
		vvi queries(m,vi(5) );
		fl(i,0,m){
			cin>>type>>L>>R;
			queries[i][0] = type;
			queries[i][1] = L-1;
			queries[i][2] = R-1;
			queries[i][3] = 0;
			queries[i][4] = 0;
		}
		fl(i,0,m){
			solveCalls(queries,i,counts,false,0);
		}
		fl(i,0,m){
			if(queries[i][0]==1)	updateRange(tree,0,0,n-1,queries[i][1],queries[i][2],queries[i][3]);
		}
		fillArrayfromTree(A,tree,0,0,n-1);
		fl(i,0,n)	cout<<A[i]<<" ";
		cout<<endl;
	}

	return 0;
}