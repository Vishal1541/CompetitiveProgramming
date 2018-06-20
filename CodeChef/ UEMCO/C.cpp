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

int n,dir;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n;
	int inside = n;
	vector< pair<int,int> > arr(n+1);	//dir-index
	fl(i,0,n){
		cin>>dir;
		arr[i] = make_pair(dir,i+1);
	}
	arr[n] = make_pair(0,n+1);
	pair<int,int> outside1,outside2,ans;
	bool out1, out2;
	while(inside>0){
		out1 = out2 = false;
		fl(i,0,n+1){
			if(arr[i].F==1){
				if(i==n){
					outside2 = arr[n];
					arr[n].F=0;
					inside--;
					out2 = true;
				}
				else{
					if(arr[i+1].F==-1){	arr[i].F=-1, arr[i+1].F=1;i++;continue;}
					else if(arr[i+1].F==0)	{arr[i+1]=arr[i],arr[i].F=0;i++;continue;}
				}
			}
			else if(arr[i].F==-1){
				if(i==0){
					inside--;
					outside1 = arr[i];
					arr[i].F=0;
					out1 = true;
				}
				else{
					if(arr[i-1].F==1)	arr[i].F=1, arr[i-1].F=-1;
					else if(arr[i-1].F==0)	arr[i-1]=arr[i], arr[i].F=0;
				}
			}
		}
		// if(arr[n].F==1){
		// 	outside2 = arr[n];
		// 	arr[n].F=0;
		// 	inside--;
		// 	out2 = true;
		// }
		// else if(arr[n].F==-1){
		// 	if(arr[n-1].F==1)	arr[n].F=1, arr[n-1].F=-1;
		// 	else if(arr[n-1].F==0)	arr[n-1]=arr[n], arr[n].F=0;
		// }
		if(inside<=0){
			if(out1 && out2){
				if(outside1.S<outside2.S)	ans = outside1;
				else 	ans = outside2;
			}
			else if(out1)	ans = outside1;
			else 	ans = outside2;
			break;
		}
		// fl(i,0,n+1)cout<<arr[i].F<<" ";
		// cout<<endl;
	}
	cout<<ans.S<<endl;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}