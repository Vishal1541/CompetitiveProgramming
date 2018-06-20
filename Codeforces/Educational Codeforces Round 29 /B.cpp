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

Int n,ans=0;

Int Min(Int a, Int b){
	if(a<b)	return a;
	return b;
}

int main(){
	ios;
	cin>>n;
	vi arr(2*n),flag(2*n,0);
	fl(i,0,2*n)	cin>>arr[i];
	sort(arr);
	Int min=9999999,idx,i,temp_min=0;
	fl(i,0,2*n){
		fl(j,0,2*n){
			if(i!=j){
				vi temp;
				fl(k,0,2*n){
					if(k!=i && k!=j)	temp.pb(arr[k]);
				}
				Int l = 0;
				sort(temp);
				temp_min = 0;
				while(1){ 
						if(l>=temp.size()-1)
							break;
						temp_min += temp[l+1] - temp[l];
						l += 2;
				}
				min = Min(min,temp_min);
			}
		}
	}

	cout<<min<<endl;

	return 0;
}