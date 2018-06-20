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
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int n,p;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n;
	vi tree(n),visited(n,0),len;
	vvi len_link(n,vi(2) );
	fl(i,0,n){
		cin>>p;
		tree[i] = (p-1);
	}
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	fl(i,0,n){
		Int leng = 0, end = tree[i];
		while(visited[end]==0){
			leng++;
			visited[end] = 1;
			end = tree[end];
		}
		if(leng>0){
			len_link[i][0] = len_link[i][1] = leng;
			len.pb(len_link[i][0]);
		}
		else len_link[i][0] = len_link[i][1] = -1;
	}
	sort(len);
	if(len.size()==1){
		cout<<n*n<<endl;
		return 0;
	}
	int M1 = -1, M2 = -1, idx1, idx2;
	M1 = len[len.size()-1];
	M2 = len[len.size()-2];
	Int ans = 0;
	bool inside = false;
	fl(i,0,n){
		if(len_link[i][0]==M1){
			idx1 = i;
			break;
		}
	}
	fl(i,0,n){
		if(len_link[i][0]==M2 && i!=idx1){
			idx2 = i;
			break;
		}
	}
	fl(i,0,n){
		if(len_link[i][1]!=-1){
			if((i==idx1 || i==idx2) && !inside){
				inside = true;
				ans += (M1+M2)*(M1+M2);
			}
			else if(i!=idx1 && i!=idx2)
				ans += len_link[i][0]*len_link[i][1];
		}
	}
	cout<<ans<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}