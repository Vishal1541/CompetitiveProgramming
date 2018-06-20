//    VISHAL ANAND
/*ip
4 3
3 1 2 3
1 3 2
2 2 3
4 -1
0
3 1 2 3
5 -2 11
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

int m,n,x,in,f,idx;
bool allZero;

int binarySearch(vi& arr, int l, int r, int x){
   if (r >= l){
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

int main(){
	ios;
	cin>>m>>n;
	vvi indices(m),values(m),t_indices(n),t_values(n);
	fl(i,0,m){
		cin>>x;
		if(x==0){
			indices[i].pb(0);
			values[i].pb(0);
			continue;
		}
		fl(j,0,x){
			cin>>in;
			indices[i].pb(in);
		}
		fl(j,0,x){
			cin>>in;
			values[i].pb(in);
		}
	}
	for(f=1; f<=n; f++){
		allZero = true;
		fl(j,0,m){
			idx = binarySearch(indices[j],0,indices[j].size()-1,f);
			if(idx==-1)	continue;
			allZero = false;
			t_indices[f-1].pb(j+1);
			t_values[f-1].pb(values[j][idx]);
		}
		if(allZero){
			t_indices[f-1].pb(0);
			t_values[f-1].pb(0);
		}
	}
	cout<<n<<" "<<m<<endl;
	fl(i,0,n){
		if(t_indices[i][0]==0){
			cout<<"0\n\n";
			continue;
		}
		cout<<t_indices[i].size()<<" ";
		fl(j,0,t_indices[i].size()){
			cout<<t_indices[i][j]<<" ";
		}
		cout<<endl;
		fl(j,0,t_values[i].size()){
			cout<<t_values[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}