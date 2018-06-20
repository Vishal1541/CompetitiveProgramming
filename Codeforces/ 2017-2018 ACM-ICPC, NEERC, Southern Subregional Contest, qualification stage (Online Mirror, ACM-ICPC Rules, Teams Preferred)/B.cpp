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

Int n,size,idx = 0,prv = -999;
mii m;

void constructSegTree(int inputArr[], int segTreeArr[], int low, int high, int pos){
	if(low==high){
		segTreeArr[pos] = inputArr[low];
		return;
	}
	int mid=(low+high)/2;
	constructSegTree(inputArr,segTreeArr,low,mid,2*pos+1);
	constructSegTree(inputArr,segTreeArr,mid+1,high,2*pos+2);
	segTreeArr[pos] = max(segTreeArr[2*pos+1],segTreeArr[2*pos+2]);
}

int findPos(int segTreeArr[], int qlow, int qhigh, int low, int high, int pos){
	if(qlow<=low && qhigh>=high)	return pos;				//total overlap
	else if(qlow>high || qhigh<low)	return -999;	//no overlap
	int mid=(low+high)/2;
	return max(findPos(segTreeArr,qlow,qhigh,low,mid,2*pos+1),	//partial overlap
				findPos(segTreeArr,qlow,qhigh,mid+1,high,2*pos+2));
}

void findAns(int segTreeArr[], int pos, mii& m,vi& flag,vvi& ans){
	if(!flag[m[segTreeArr[pos]]] && segTreeArr[pos]>=prv){
		ans[idx].pb(segTreeArr[pos]);
		prv = segTreeArr[pos];
		flag[m[segTreeArr[pos]]] = 1;
	}
	else if(!flag[m[segTreeArr[pos]]] && segTreeArr[pos]<prv){
		idx++;
		ans[idx].pb(segTreeArr[pos]);
		prv = segTreeArr[pos];
		flag[m[segTreeArr[pos]]] = 1;
	}
	if(pos==0)	return;
	findAns(segTreeArr, (pos-1)/2, m, flag, ans);
}

unsigned int nextPowerOf2(unsigned int n)
{
  unsigned count = 0;
  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}

int main(){
	ios;
	Int position;
	cin>>n;
	size = nextPowerOf2(n);
	int arr[n], segTree[size];
	vi flag(n,0);
	vvi ans(n);
	fl(i,0,n){
		cin>>arr[i];
		m[arr[i]] = i;
	}
	constructSegTree(arr,segTree,0,n-1,0);
	fl(i,0,n){
		position = findPos(segTree,i,i,0,n-1,0);
		findAns(segTree,position,m,flag,ans);
		flag[m[arr[i]]] = 1;
	}
	fl(i,0,idx+1){
		fl(j,0,ans[i].size()){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}