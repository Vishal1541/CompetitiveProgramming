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
8
ab
ab
aba
cde
ab
cd
abba
axyz
abba
abxy
abxy
abca
abc
axy
abcbax
abcbaa
*/
int main(){
	ios;
	Int T;
	cin>>T;
	while(T--){
		string s,t;
		cin>>s>>t;
		map<char,int[2]> ms,mt;
		map<char,int[2]> :: iterator its,itt,it_temp;
		fl(i,0,s.length()){
			ms[s[i]][0]++;
			mt[t[i]][0]++;
		}

		for(its=ms.begin(); its!=ms.end(); its++){
			it_temp = mt.find(its->F);
			if(it_temp!=mt.end())
				its->S[1]=1;
		}
		for(itt=mt.begin(); itt!=mt.end(); itt++){
			it_temp = ms.find(itt->F);
			if(it_temp!=ms.end())
				itt->S[1]=1;
		}

		string winner="X";
		vector<int> flag(7,0);
		for(its=ms.begin(); its!=ms.end(); its++){
			if(its->S[0]==1 && its->S[1]==0){
				flag[0]=1;
				break;
			}
		}
		for(itt=mt.begin(); itt!=mt.end(); itt++){
			if(itt->S[0]==1 && itt->S[1]==0){
				flag[1]=1;
				break;
			}
		}

		for(its=ms.begin(); its!=ms.end(); its++){
			if(its->S[0]>1 && its->S[1]==0){
				flag[2]=1;
				break;
			}
		}
		for(itt=mt.begin(); itt!=mt.end(); itt++){
			if(itt->S[0]>1 && itt->S[1]==0){
				flag[3]=1;
				break;
			}
		}

		int temp1=0, temp2=1;
		for(its=ms.begin(); its!=ms.end(); its++){
			if(its->S[0]==1 && its->S[1]==0){
				temp1=1;
				break;
			}
		}
		for(itt=mt.begin(); itt!=mt.end(); itt++){
			if(itt->S[1]==0){
				temp2=0;
				break;
			}
		}
		if(temp1 && temp2)	flag[4]=1;

		int temp=1;
		for(its=ms.begin(); its!=ms.end(); its++){
			if(its->S[1]==0){
				temp=0;
				break;
			}
		}
		if(temp)	flag[5]=1;
		temp=1;
		for(itt=mt.begin(); itt!=mt.end(); itt++){
			if(itt->S[1]==0){
				temp=0;
				break;
			}
		}
		if(temp)	flag[6]=1;


		if(flag[2])					winner="A";
		else if(flag[3])			winner="B";
		else if(flag[0] && flag[1])	winner="B";
		else if(flag[4])			winner="A";
		else if(flag[5])			winner="B";
		else if(flag[6])			winner="A";
		else						winner="B";
		cout<<winner<<endl;
	}

	return 0;
}