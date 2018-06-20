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

Int n,k,size,tempI,tempC,delay,ans=0,flag[600005]={0},depart[300005];
si timeith;
si_it itr;

struct tree{
	Int cost,ith;
};

void Heapify(tree A[], Int index, Int &heapSize);


void swap(tree A[], int i, int j){
	tree temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i+1;
}
int parent(int i){
	return i/2;
}

void buildHeap(tree A[], Int low, Int high,Int &heapSize){
	Int length = high-low+1;
	for(Int i=length/2-1; i>=low; i--)
		Heapify(A,i,heapSize);
}

void Heapify(tree A[], Int index, Int &heapSize){
	Int l = left(index+1);
	Int r = right(index+1);
	Int index_change = index;
	Int largest = A[index].cost;
	if(l<=heapSize) if(A[l-1].cost>largest)	{largest = A[l-1].cost; index_change = l-1;}
	if(r<=heapSize) if(A[r-1].cost>largest)	{largest = A[r-1].cost; index_change = r-1;}
	if(index != index_change){
		swap(A,index_change,index);
		Heapify(A, index_change, heapSize);
	}
}

int main(){
	ios;
	cin>>n>>k;
	fl(i,k+1,n+k+2)	timeith.insert(i);
	tree t[n];
	fl(i,0,n){
		cin>>t[i].cost;
		t[i].ith = i+1;
	}
	size = n;
	buildHeap(t,0,n-1,size);
	fl(i,0,n){
		tempI = t[0].ith;
		tempC = t[0].cost;
		delay = 0;
		// if(tempI<=k){
		// 	delay = k+1-tempI;
		// 	tempI = k+1;

		// }
		itr = timeith.lower_bound(tempI);
		// while(flag[tempI]!=0)	{
		// 	tempI++;
		// 	delay++;
		// }
		// cout<<tempI<<delay<<"..";
		// while(tempI>*itr){
		// 	itr++;
		// }
		delay += *itr-tempI;
		tempI = *itr;
		timeith.erase(itr);
		// flag[tempI] = 1;	
		ans += delay*tempC;
		depart[t[0].ith] = delay+t[0].ith;
		swap(t,0,size-1);
		size--;
		Heapify(t,0,size);
	}
	cout<<ans<<endl;
	fl(i,1,n+1)	cout<<depart[i]<<" ";
	cout<<endl;

	return 0;
}