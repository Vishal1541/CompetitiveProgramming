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
1
2 9
! 0
?
! 1
?
! 0
?
! 0
! 0
? 
*/

Int T,N,Q,C;

string binSum(string& a, string& b){
	string c="";
	int carry=0;
	for(int i=N-1; i>=0; i--){
		vi count(2,0);
		count[a[i]-'0']++;
		count[b[i]-'0']++;
		if((count[1]+carry)==0){
			c = "0" + c;
			carry = 0;
		}
		else if((count[1]+carry)==1){
			c = "1" + c;
			carry = 0;
		}
		else if((count[1]+carry)==2){
			c = "0" + c;
			carry = 1;
		}
		else if((count[1]+carry)==3){
			c = "1" + c;
			carry = 1;
		}
	}
	return c;
}

/*string to_Binary(Int n)
{
    string r;
    if(n==0)	return "0";
    while(n!=0){
    	r=(n%2==0 ?"0":"1")+r; 
    	n/=2;
    }
    return r;
}
*/
int main(){
	ios;
	cin>>T;
	while(T--){
		cin>>N>>Q;	//N=length of binary representation
		Int NO_OF_NODES = pow(2,N+1)-1;
		string X="";
		fl(i,0,N)	X = X + "0";
		vi flag(NO_OF_NODES,0);
		flag[0]=1;
		Int visited=1;
		while(Q--){
			char ch;
			cin>>ch;
			if(ch=='!'){
				cin>>C;
				string twoPowerC="";
				Int node=0;
				fl(i,0,C)	twoPowerC = twoPowerC+"0";
				twoPowerC = "1"+twoPowerC;
				Int rem_len = N-twoPowerC.length();
				fl(i,0,rem_len)	twoPowerC = "0"+twoPowerC;
				X = binSum(X,twoPowerC);

				//------------------------------
				//X = (X%mod+(Int)(pow(2,C))%mod)%mod;
				//string bin=to_Binary(X);
				//string bin = bitset<2>(X).to_string();
				//fl(i,0,N-bin.length())	bin="0"+bin;
				//cout<<bin<<" ";
				fl(i,0,N){
					if(X[i]=='0')	node = node*2+1;
					else 			node = node*2+2;
					if(!flag[node]){
						flag[node]=1;
						visited++;
					}
				}
			}
			else{
				cout<<visited<<endl;
			}
		}
	}

	return 0;
}