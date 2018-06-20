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

struct cmp{
	bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
		return p1.F>p2.F;
	}
};

int n,a,b,q,k;
int l[200009];
set<pair<int,int>,cmp > s;
set<pair<int,int>,cmp > :: iterator itr;
vi max_arr(200009,-1);

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;
	cin>>n;
	vector<set<int> >  lists(n+9);
	fl(i,1,n+1){
		cin>>a>>b;
		lists[a].insert(b);
		if(max_arr[a]<b)	max_arr[a] = b;
	}
	fl(i,1,200009){
		if(max_arr[i]>0)
			s.insert(make_pair(max_arr[i],i));
	}
	cin>>q;
	while(q--){
		cin>>k;
		fl(i,0,k){
			cin>>l[i];
			if(max_arr[l[i]]>0)
				s.erase(make_pair(max_arr[l[i]],l[i]));
		}
		if(s.empty())	cout<<"0 0\n";
		else if(s.size()==1)	cout<<s.begin()->S <<" "<< *lists[s.begin()->S].begin()<<endl;
		else{
			itr = s.begin();
			itr++;
			cout<<s.begin()->S <<" "<< *lists[s.begin()->S].upper_bound(itr->F)<<endl;
		}
		fl(i,0,k){
			if(max_arr[l[i]]>0)
				s.insert(make_pair(max_arr[l[i]],l[i]));
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}