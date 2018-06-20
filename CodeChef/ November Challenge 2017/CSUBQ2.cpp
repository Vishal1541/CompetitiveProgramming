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
si brk,range;
si_it itr_idx,itr_low,itr_high;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>N>>Q>>L>>R;
    vi arr(N+5,0);
    brk.insert(0);
    brk.insert(N+1);
	while(Q--){
        cin>>type;
        if(type==1){
            cin>>x>>y;
            if(y>=L && y<=R){
                range.insert(y);
            }
            else if(y>R){
                brk.insert(y);
            }
        }
        else{
            cin>>l>>r;
            itr_idx = range.lower_bound(l);
            if(itr_idx==range.end()){
                cout<<"0\n";
                continue;
            }
            if(*itr_idx>r){
                cout<<"0\n";
                continue;
            }
            itr_low = itr_high = brk.lower_bound(*itr_idx);
            itr_low--;
            
        }
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}