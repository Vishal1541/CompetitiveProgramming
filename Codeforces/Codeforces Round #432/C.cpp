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
#define PI 3.14159265

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int n,noOfBad=0;
double theta,x,y;
bool yes=true;

int main(){
	ios;
	cin>>n;
	Int arr[n][5];
	vi bad(n,0);
	fl(i,0,n)	cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4];
	fl(i,0,n){
		fl(j,0,n){
				x = sqrt( (arr[j][0]-arr[i][0])*(arr[j][0]-arr[i][0]) + (arr[j][1]-arr[i][1])*(arr[j][1]-arr[i][1]) + (arr[j][2]-arr[i][2])*(arr[j][2]-arr[i][2]) + (arr[j][3]-arr[i][3])*(arr[j][3]-arr[i][3]) + (arr[j][4]-arr[i][4])*(arr[j][4]-arr[i][4]) );
			if(i!=j){
				fl(k,0,n){
					if(j!=k){
						y = sqrt( (arr[k][0]-arr[i][0])*(arr[k][0]-arr[i][0]) + (arr[k][1]-arr[i][1])*(arr[k][1]-arr[i][1]) + (arr[k][2]-arr[i][2])*(arr[k][2]-arr[i][2]) + (arr[k][3]-arr[i][3])*(arr[k][3]-arr[i][3]) + (arr[k][4]-arr[i][4])*(arr[k][4]-arr[i][4]) );
						theta = acos( ((arr[j][0]-arr[i][0])*(arr[k][0]-arr[i][0]) + (arr[j][1]-arr[i][1])*(arr[k][1]-arr[i][1]) + (arr[j][2]-arr[i][2])*(arr[k][2]-arr[i][2]) + (arr[j][3]-arr[i][3])*(arr[k][3]-arr[i][3]) + (arr[j][4]-arr[i][4])*(arr[k][4]-arr[i][4]))/(x*y)  )*180.0/PI;
						// cout<<"theta "<<theta<<"..";
						if( theta<90 ){
							if(!bad[i]){
								bad[i] = 1;
								noOfBad++;
							}
							break;
						}
					}
				}
				if(bad[i])	break;
			}
		}
	}
	cout<<n-noOfBad<<endl;
	fl(i,0,n)	if(!bad[i])	cout<<i+1<<endl;
	return 0;
}