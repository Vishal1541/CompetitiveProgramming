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
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int n,m,a,b,mul;
string s;
vi equality(1009), indegree(1009,0);
vector<char> colors(1009);
vvi graph(1009);
vvi samecolors(1009);

struct WRB{
	int A,B;
	char sign;
};

bool isSign(char a){
	return (a=='>' || a=='<' || a=='=');
}

bool dfs(int node, int turn){
	// visited[node] = 1;
	if(turn==2){
		colors[node] = 'W';
		return true;
	}
	bool found = false;
	fl(i,0,graph[node].size()){
			found = dfs(graph[node][i], turn+1);
	}
	if (found && turn==1){colors[node] = 'R';return true;}
	else if(found && turn==0){colors[node] = 'B';return true;}
	else 	return false;
}

bool cmp(const WRB &a, const WRB &b){return (a.A<b.A);}

int main(){

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	
	ios;
	cout.precision(10);
	cout<<fixed;


	fl(i,0,1009){equality[i] = i; colors[i] = '?';}

	cin>>n>>m;

	WRB arr[m];
	fl(j,0,m){
		cin>>s;
		mul = 1;
		a = b = 0;
		int i=0;
		while(!isSign(s[i])){
			a = a*mul+(s[i]-'0');
			mul *= 10;
			i++;
		}
		arr[j].sign = s[i];
		i++;
		mul = 1;
		while(i<s.length()){
			b = b*mul+(s[i]-'0');
			i++;
		}
		if(arr[j].sign=='='){
			arr[j].A = min(a,b);
			arr[j].B = max(a,b);
		}
		else{
			arr[j].A = a;
			arr[j].B = b;
		}
	}
	sort(arr,arr+m,cmp);
	fl(i,0,m){
		if(arr[i].sign=='='){
			equality[arr[i].B] = equality[arr[i].A];
			samecolors[equality[arr[i].A]].pb(arr[i].B);
		}	
	}
	fl(i,0,m){
		if(arr[i].sign=='>'){
			graph[equality[arr[i].B]].pb(equality[arr[i].A]);
			indegree[equality[arr[i].A]]++;
		}
		else if(arr[i].sign=='<'){
			graph[equality[arr[i].A]].pb(equality[arr[i].B]);
			indegree[equality[arr[i].B]]++;
		}
	}
	fl(i,0,m){
		if(arr[i].sign == '<'){
			if(indegree[equality[arr[i].A]]==0){
				bool traverse = dfs(equality[arr[i].A],0);
			}
		}
		else if(arr[i].sign == '>'){
			if(indegree[equality[arr[i].B]]==0){
				bool traverse = dfs(equality[arr[i].B],0);
			}
		}
	}
	fl(i,0,1009){
		fl(j,0,samecolors[i].size()){
			colors[samecolors[i][j]] = colors[i];
		}
	}
	fl(i,1,n+1)	cout<<colors[i];

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}