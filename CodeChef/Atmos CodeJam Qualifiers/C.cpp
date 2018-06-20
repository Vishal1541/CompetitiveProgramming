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

Int N,Q,type,x,y,L,R,parity,size;
vi segtree_even(1048576+5,0),segtree_odd(1048576+5,0);

Int nextPowerOf2(Int n)
{
  Int count = 0;
 
  /* First n in the below condition is for the case where n is 0*/
  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}


void queryTree(auto& segTreeArr, Int idx, Int low, Int high, Int pos, Int& addd){
	if(idx>high || idx<low)	return;
	addd += segTreeArr[pos];
	if(idx==low && idx==high)	return;
	queryTree(segTreeArr,idx,low,(low+high)/2,2*pos,addd);
	queryTree(segTreeArr,idx,(low+high)/2+1,high,2*pos+1,addd);
}

void updateRange(auto& tree, Int node, Int start, Int end, Int l, Int r, Int val)
{
    // out of range
    if (start > end or start > r or end < l)
        return;
    //total overlap
    if (l<=start && r>=end){
        tree[node] += val;
        return;
    }

    Int mid = (start + end) / 2;
    updateRange(tree,node*2, start, mid, l, r, val);
    updateRange(tree,node*2 + 1, mid + 1, end, l, r, val);
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>N>>Q;
	// size = nextPowerOf2(1000000);
	vi arr(N+1,0),even(N+1,0),odd(N+1,0);
	fl(i,1,N+1)	cin>>arr[i];
	// constructSegTree(arr,segtree_even,1,N,1);
	// constructSegTree(arr,segtree_odd,1,N,1);
	fl(i,1,N+1){
		if(arr[i]%2==0){
			even[i] = even[i-1]+arr[i];
			odd[i] = odd[i-1];
		}
		else{
			odd[i] = odd[i-1]+arr[i];
			even[i] = even[i-1];
		}
	}
	while(Q--){
		cin>>type;
		if(type==1){
			cin>>x>>y;
			if(arr[x]%2==1 && (arr[x]+y)%2==1 ){
				updateRange(segtree_odd,1,1,N,x,N,y);
			}
			else if(arr[x]%2==0 && (arr[x]+y)%2==0 ){
				updateRange(segtree_even,1,1,N,x,N,y);
			}
			else if(arr[x]%2==1 && (arr[x]+y)%2==0 ){
				updateRange(segtree_even,1,1,N,x,N,arr[x]+y);
				updateRange(segtree_odd,1,1,N,x,N,-arr[x]);
			}
			else if(arr[x]%2==0 && (arr[x]+y)%2==1 ){
				updateRange(segtree_even,1,1,N,x,N,-arr[x]);
				updateRange(segtree_odd,1,1,N,x,N,arr[x]+y);
			}
			arr[x] += y;
		}
		else{
			cin>>L>>R>>parity;
			Int ans,addd1 = 0, addd2 = 0;
			if(parity==0){
				queryTree(segtree_even,R,1,N,1,addd1);
				queryTree(segtree_even,L-1,1,N,1,addd2);
				ans = even[R]+addd1-(even[L-1]+addd2);
			}
			if(parity==1){
				queryTree(segtree_odd,R,1,N,1,addd1);
				queryTree(segtree_odd,L-1,1,N,1,addd2);
				ans = odd[R]+addd1-(odd[L-1]+addd2);
			}
			cout<<ans<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}