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

int n,p1=1,changes = 0;
vi flag(200005,0),used(200005,0),ans;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n;
	int arr[n];
	fl(i,0,n){
		cin>>arr[i];
		flag[arr[i]]++;
	}
	fl(i,0,200005){
		if(flag[i]>1)	changes += flag[i]-1;
	}
	cout<<changes<<endl;
	fl(i,0,n){
		if(flag[arr[i]]==1 && used[arr[i]]==0)
			cout<<arr[i]<<" ";
		else{
			if(p1<=arr[i]){
				while(flag[p1]!=0 && p1<arr[i])p1++;
				if(flag[p1]==0){
					cout<<p1<<" ";
					flag[p1]=1;
				}
				else if(!used[arr[i]]){
					cout<<arr[i]<<" ";
					used[arr[i]] = 1;
				}
				else{
					while(flag[p1]!=0)	p1++;
					cout<<p1<<" ";
					flag[p1] = 1;
				}
			}
			else{
				while(flag[p1]!=0)	p1++;
				cout<<p1<<" ";
				flag[p1] = 1;
			}
		}
		if(flag[arr[i]]!=1)
			flag[arr[i]]--;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}