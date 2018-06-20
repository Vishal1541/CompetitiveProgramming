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

Int N,Q,L,R,l,r,x,y,type;

struct segtree{
	int i4,i7,k2,k3,b,val;
};
segtree tree[600000];

void buildSegmentTree(){
	fl(i,1,600000){
		tree[i].b = i;
		tree[i].k2 = tree[i].k3 = tree[i].val = 0;
		tree[i].i4 = i+1;
		tree[i].i7 = i-1;
	}
}

void update(Int node, Int start, Int end, Int idx, Int val)
{
    if(start == end)
    {
        // Leaf node
        if(val>R){
        	tree[node].k2 = tree[node].k3 = 0;
        	tree[node].i4 = tree[node].i7 = tree[node].b = idx;
        	tree[node].val = 0;
        }
        else if(val>=L && val<=R){
        	tree[node].k2 = tree[node].k3 = 1;
        	tree[node].i4 = idx+1;
        	tree[node].i7 = idx-1;
        	tree[node].b = idx;    
        	tree[node].val = 1;    	
        }
        else{
        	tree[node].k2 = tree[node].k3 = 0;
        	tree[node].i4 = idx+1;
        	tree[node].i7 = idx-1;
        	tree[node].b = idx;
        	tree[node].val = 0;
        }
    }
    else
    {
        Int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children

        tree[node].i7 = tree[2*node].i7;
        tree[node].i4 = tree[2*node+1].i4;
        if(tree[2*node].i4>mid && tree[2*node].i7<start
        	&& tree[2*node+1].i4>end && tree[2*node+1].i7<=mid){
	        tree[node].k3 = tree[2*node].k3 + tree[2*node+1].k3;
	        tree[node].k2 = tree[2*node].k3 + tree[2*node+1].k3;
	    }
	    else if(tree[2*node].i4>mid && tree[2*node].i7<start){
	        tree[node].k3 = tree[2*node].k3 + tree[2*node+1].k3;
	    	tree[node].k2 = tree[2*node+1].k2;
	    }
	    else if(tree[2*node+1].i4>end && tree[2*node+1].i7>=mid){
	    	tree[node].k3 = tree[2*node].k3;
	    	tree[node].k2 = tree[2*node].k2 + tree[2*node+1].k2;
	    }
	    else{
	    	tree[node].k3 = tree[2*node].k3;
	    	tree[node].k2 = tree[2*node+1].k2;
	    }
        tree[node].val = tree[2*node+1].i7*tree[2*node].k2
        				-tree[2*node].i4*tree[2*node+1].k3
        				-2*tree[2*node].k2*tree[2*node+1].k3
        				-tree[2*node].b*tree[2*node].k2
        				+tree[2*node].b*tree[2*node+1].k3
        				+tree[2*node+1].k3;
        tree[node].val += tree[2*node].val + tree[2*node+1].val;
    }
}

segtree query(Int node, Int start, Int end, Int l, Int r)
{
	segtree t3;
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        t3.val = -1;
        return t3;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    Int mid = (start + end) / 2;
    segtree t1 = query(2*node, start, mid, l, r);
    segtree t2 = query(2*node+1, mid+1, end, l, r);
    
    if(t1.val==-1)	return t2;
    if(t2.val==-1)	return t1;

    t3.i7 = t1.i7;
        t3.i4 = t2.i4;
        if(t1.i4>mid && t1.i7<start
        	&& t2.i4>end && t2.i7<=mid){
	        t3.k3 = t1.k3 + t2.k3;
	        t3.k2 = t1.k3 + t2.k3;
	    }
	    else if(t1.i4>mid && t1.i7<start){
	        t3.k3 = t1.k3 + t2.k3;
	    	t3.k2 = t2.k2;
	    }
	    else if(t2.i4>end && t2.i7>=mid){
	    	t3.k3 = t1.k3;
	    	t3.k2 = t1.k2 + t2.k2;
	    }
	    else{
	    	t3.k3 = t1.k3;
	    	t3.k2 = t2.k2;
	    }
        t3.val = t2.i7*t1.k2
        				-t1.i4*t2.k3
        				-3*t1.k2*t2.k3
        				-t1.b*t1.k2
        				+t1.b*t2.k3+t2.k3;
        t3.val += t1.val+t2.val;
        return t3;
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>N>>Q>>L>>R;
	buildSegmentTree();
	while(Q--){
		cin>>type;
		if(type==1){
			cin>>x>>y;
			update(1,1,N,x,y);
		}
		else{
			cin>>l>>r;
			segtree ans_node = query(1,1,N,l,r);
			cout<<ans_node.val<<endl;
		}
	}
	fl(i,1,8)	cout<<tree[i].val<<" ";

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}