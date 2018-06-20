//    VISHAL ANAND
/*ip
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/
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
#define MOD 1000000007
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

Int T,N,Q,I,J,val;
bool ans;

struct List{
	Int index,value;
	struct List *next;
};

void dfs(auto& arr,Int vertex,vi& visited, Int& diff,bool& found, bool& isPossible){
	visited[vertex]=1;
	if(vertex==J){
		found = true;
		if(diff%2!=val)	isPossible = false;
		return;
	}
	Int temp_diff=diff;
	List *temp=arr[vertex].next;
	while(temp!=NULL){
		temp_diff = temp_diff+temp->value;
		if(!visited[temp->index])
			dfs(arr, temp->index, visited, temp_diff,found,isPossible);
		if(found)	break;
		temp = temp->next;
	}
}

bool canItInsert(auto& arr,bool& found, bool& isPossible){
	Int diff=0;
	// List *temp=arr[J].next;
	// bool opp=true;
	// while(temp!=NULL){
	// 	if(temp->value==I){
	// 		opp=false;
	// 		ans=false;
	// 		break;
	// 	}
	// 	temp = temp->next;
	// }
	// if(!opp)	return false;
	vi visited(N+1,0);
	dfs(arr,I,visited,diff,found,isPossible);
	if(!found)	return true;
	return false;
}

void insertArr(auto& arr){
	List *temp = arr[I].next;
	temp = new List;
	temp->index = J;
	temp->value = val;
	temp->next = arr[I].next;
	arr[I].next = temp;

	temp = arr[J].next;
	temp = new List;
	temp->index = I;
	temp->value = val;
	temp->next = arr[J].next;
	arr[J].next = temp;
}

int main(){
	ios;
	cin>>T;
	while(T--){
		cin>>N>>Q;
		ans=true;
		List *arr = new List[N+1];
		fl(i,0,N+1)	arr[i]={0,0,NULL};
		while(Q--){
			cin>>I>>J>>val;
			if(I==J and val!=0)	ans=false;
			if(ans){
				bool found=false, isPossible=true;
				bool check = canItInsert(arr,found,isPossible);
				if(check)	insertArr(arr);
				else if(found && !isPossible)	ans = false;
			}
		}
		cout<<(ans?"yes\n":"no\n");
	}

	return 0;
}