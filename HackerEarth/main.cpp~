//VISHAL ANAND
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

int T,N,Q,L,R,X,V,type,sizeTree,ans=0,str_len;
string bin;

struct node{
     Int val;
     int len;
};

int nextPowerOf2(int n)
{
  int count = 0;
  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}

void constructSegTree(string inputArr, node segTreeArr[], int low, int high, int pos){
	if(low==high){
		segTreeArr[pos].val = inputArr[low]-'0';
		segTreeArr[pos].len = 1;
		return;
	}
	int mid=(low+high)/2;
	constructSegTree(inputArr,segTreeArr,low,mid,2*pos+1);
	constructSegTree(inputArr,segTreeArr,mid+1,high,2*pos+2);
	
	segTreeArr[pos].len = segTreeArr[2*pos+1].len + segTreeArr[2*pos+2].len;
	Int shifted = segTreeArr[2*pos+1].val;
	segTreeArr[pos].val = ((shifted << segTreeArr[2*pos+2].len) + segTreeArr[2*pos+2].val)%5;
	cout<<segTreeArr[pos].val<<" "<<segTreeArr[pos].len<<"-";
}

int Query(node segTreeArr[], int qlow, int qhigh, int low, int high, int pos){
	if(qlow<=low && qhigh>=high)	return segTreeArr[pos].val%5;				//total overlap
	else if(qlow>high || qhigh<low)	return 0;	//no overlap
	int mid=(low+high)/2;
	return (Query(segTreeArr,qlow,qhigh,low,mid,2*pos+1) + Query(segTreeArr,qlow,qhigh,mid+1,high,2*pos+2))%5;
}

void update(node tree[], int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        tree[node].val = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(tree,2*node+1, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(tree,2*node+2, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        Int shifted = tree[2*node+1].val;
        tree[node].val = shifted << tree[2*node+2].len + tree[2*node+2].val;
    }
}

int main(){
     cin>>T;
     while(T--){
          cin>>bin;
          str_len = bin.length();
          sizeTree = nextPowerOf2(str_len);
          node segtree[sizeTree];
          constructSegTree(bin,segtree,0,str_len-1,0);
          /*cin>>Q;
          while(Q--){
               cin>>type;
               if(type==0){
                    cin>>L>>R;
                    ans = Query(segtree,L,R,0,str_len-1,0);
                    cout<<ans<<endl;
               }
               else{     
                    cin>>X>>V;
                    update(segtree,0,0,str_len-1,X,V);
               }
          }*/
     }

     return 0;
}
