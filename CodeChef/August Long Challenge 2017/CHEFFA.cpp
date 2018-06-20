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
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}
/*ip
3
3
2 3 1
2
2 2
3
1 2 3
*/

Int T,N,Ai,ans;
set<string> s;
set<string> :: iterator itr;

void calc(string str){
	fl(i,0,str.length()-1){
		if(str[i]!='0' && str[i+1]!='0'){
			string temp=str;
			temp[i]--,temp[i+1]--;
			if(i==str.length()-2){
				temp.append("1");
			}
			else{
				temp[i+2]++;
			}
			itr = s.find(temp);
			if(itr==s.end()){
				s.insert(temp);
				ans++;
				calc(temp);
			}
		}
	}
}

int main(){
	ios;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		string str="";
		s.clear();
		ans=1;
		fl(i,0,N)	cin>>arr[i];
		fl(i,0,N){
			str.append(to_string(arr[i]));
		}
		calc(str);
		cout<<ans<<endl;
	}

	return 0;
}