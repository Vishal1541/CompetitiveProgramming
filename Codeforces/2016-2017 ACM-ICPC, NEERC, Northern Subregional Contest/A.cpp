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
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int n,tree_size;

struct s{
	Int cc,tf,id;
};
s arr[100009];
vector<Int> up_down(100009,0), down_up(100009,0),tree_up_down(931072,0),tree(931072,0), ans(100009,0);

bool cmp(const s& a, const s& b){return a.cc<b.cc;}

Int nextPowerOf2(Int n)
{
  Int count = 0;
  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}

void update(vi &tree, Int node, Int start, Int end, Int idx, Int val)
{
    if(start == end)
    {
        // Leaf node
        tree[node] += val;
    }
    else
    {
        Int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(tree, 2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(tree, 2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

Int query(vi& tree, Int node, Int start, Int end, Int l, Int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    Int mid = (start + end) / 2;
    Int p1 = query(tree, 2*node, start, mid, l, r);
    Int p2 = query(tree, 2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

int main(){

	// freopen("codecoder.in","r",stdin);
	// freopen("codecoder.out","w",stdout);

	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n;
	fl(i,0,n){
		cin>>arr[i].cc>>arr[i].tf;
		arr[i].id = i+1;
	}
	up_down[0] = 0;
	update(tree_up_down,1,1,n,arr[0].cc,1);
	fl(i,1,n){
		up_down[i] = query(tree_up_down,1,1,n,1,arr[i].cc);
		update(tree_up_down,1,1,n,arr[i].cc,1);
	}

	update(tree, 1,1,n,arr[n-1].tf,1);
	down_up[n-1] = 0;
	for(int i=n-2; i>=0; i--){
			down_up[i] = query(tree, 1,1,n,1,arr[i].tf-1);
		update(tree, 1,1,n,arr[i].tf,1);
	}
	fl(i,0,n)	cout<<up_down[i]+down_up[i]<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}