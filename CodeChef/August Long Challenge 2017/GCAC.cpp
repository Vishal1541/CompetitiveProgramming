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
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}
/*ip
1
5 6
5000 10000 3000 20 100
10000 2
800 2
600 1
10 8
1000 9
2000 10
111111
100000
000000
000001
100100
*/

Int T,N,M;

int main(){
	ios;
	cin>>T;
	while(T--){
		cin>>N>>M;
		vi minSalary(N),offeredSalary(M),maxJobOffers(M),offeredTill(M,0);
		Int qual, selectedStudents[2][N];
		fl(i,0,N){
			cin>>minSalary[i];
			selectedStudents[0][i]=0;
			selectedStudents[1][i]=0;
		}
		fl(i,0,M)	cin>>offeredSalary[i]>>maxJobOffers[i];
		fl(i,0,N){
			Int comp=-1,Max=-1;
			fl(j,0,M){
				char ch;
				cin>>ch;
				qual=ch-'0';
				if(qual==1 && offeredSalary[j]>=minSalary[i] && offeredTill[j]<maxJobOffers[j] && offeredSalary[j]>Max){
					comp = j;
					Max = offeredSalary[j];
				}
			}
			if(comp!=-1){
				offeredTill[comp]++;
				selectedStudents[0][i]=1;
				selectedStudents[1][i]=offeredSalary[comp];
			}
		}
		Int compLeft=0, sel=0, totalSal=0;
		fl(i,0,N){
			if(selectedStudents[0][i]==1){
				sel++;
				totalSal+=selectedStudents[1][i];
			}
		}
		fl(i,0,M)
			if(offeredTill[i]==0)	compLeft++;
		cout<<sel<<" "<<totalSal<<" "<<compLeft<<endl;
	}

	return 0;
}