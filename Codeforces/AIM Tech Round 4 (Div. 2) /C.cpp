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
#define us unordered_set
#define um unordered_map
#define mii map<Int,Int>
#define qi queue<Int>
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
// #define sort(v) sort(v.begin(),v.end());
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

Int n,inp,idx,ansptr=0;

Int binarySearch(Int arr[], Int l, Int r, Int x)
{
    if (r>=l)
    {
        Int mid = l + (r - l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}

int main(){
	ios;
	cin>>n;
	Int arr1[n],arr2[n],indexarr[n],flag[n];
	vvi ans(n);
	fl(i,0,n){
		cin>>inp;
		arr1[i]=arr2[i]=inp;
		flag[i]=0;
	}
	sort(arr2,arr2+n);
	/*fl(i,0,n){
		idx=binarySearch(arr2,0,n-1,arr1[i]);
		indexarr[idx]=i;
	}*/
	for(int i=0; i<n; i++){
		if(!flag[i]){
			flag[i]=1;
			ans[ansptr].pb(i+1);
			idx=binarySearch(arr2,0,n-1,arr1[i]);
			while(!flag[idx]){
				flag[idx]=1;
				ans[ansptr].pb(idx+1);
				idx=binarySearch(arr2,0,n-1,arr1[idx]);
			}
			ansptr++;
		}
	}
	cout<<ansptr<<endl;
	fl(i,0,ansptr){
		cout<<ans[i].size()<<" ";
		fl(j,0,ans[i].size())	cout<<ans[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}