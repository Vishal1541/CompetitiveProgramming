//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
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
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int n,inp1,inp2;

struct data{
	int l,r;
};

void merge(data *d, int l, int m, int u){
	int p1 = l, p2 = m+1;
	data r[u-l+2];
	int i=0,k,x;
	while(!(p1==(m+1) || p2==(u+1) )){
		if(d[p1].l < d[p2].l)	r[i++] = d[p1++];
		else				r[i++] = d[p2++];
	}
	if(p1==m+1)
		for(k=p2;k<=u;k++)		r[i++] = d[k];
	else
		for(k=p1;k<=m;k++)		r[i++] = d[k];
	i=0;
	for(x=l;x<=u;x++)			d[x] = r[i++];
}
void mergeSort(data *d, int l, int u){
	int m = (l+u)/2,i;
	if(l<u){
		mergeSort(d,l,m);
		mergeSort(d,m+1,u);
		merge(d,l,m,u);
	}
}

int main(){
	ios;
	cin>>n;
	data arr[n];
	fl(i,0,n){
		cin>>inp1>>inp2;
		arr[i].l=inp1;
		arr[i].r=inp2;
	}
	mergeSort(arr,0,n-1);
	int t1=-1, t2=-1,count=0;
	fl(i,0,n){
		if(t1==-1){
			t1=i;
			count++;
		}
		else if(t2==-1){
			t2=i;
			count++;
		}
		else{
			if(!(arr[i].l >= arr[t1].l && arr[i].l <= arr[t1].r)){
				t1=i;
				count++;
			}
			else if(!(arr[i].l >= arr[t2].l && arr[i].l <= arr[t2].r)){
				t2=i;
				count++;
			}
			else	break;
		}
	}
	cout<<(count==n?"YES\n":"NO\n");

	return 0;
}