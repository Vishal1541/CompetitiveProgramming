//		VISHAL ANAND
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <functional>

using namespace std;

#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define us unordered_set
#define um unordered_map
#define mapi map<Int,Int>
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());

int N,X,Y;
um<int,int> m;
si duration;
vi V,W;

int findInV(int S, int L, int U){
	int mid = (L+U)/2;
	cout<<" mid "<<mid;
	int mid_val = V[mid];
	if(mid_val==S)
		return S;
	if(L==U){
		if(L==0)
			return V[L];
		return (V[L]>S)? V[L-1]:V[L];
	}
	if(mid_val<S)
		return findInV(S,mid+1,U);
	return findInV(S,L,mid-1);

}

int findInW(int e, int l, int u){
	int mid = (l+u)/2;
	int mid_val = W[mid];
	if(mid_val==e)
		return e;
	if(l==u){
		if(l==W.size()-1)
			return W[l];
		return (W[l]>e)? W[l]:W[l+1];
	}
	if(mid_val<e)
		findInW(e,mid+1,u);
	findInW(e,l,mid-1);

}

int main(){
	cin>>N>>X>>Y;
	fl(i,0,N){
		int s,e;
		cin>>s>>e;
		m[s]=e;
	}
	fl(i,0,X){
		int v;
		cin>>v;
		V.pb(v);
	}
	sort(V);
	fl(i,0,Y){
		int w;
		cin>>w;
		W.pb(w);
	}
	sort(W);
	for(um<int,int> :: iterator itr=m.begin(); itr!=m.end(); itr++){
		int s = itr->first;
		int e = itr->second;
		int v = findInV(s,0,V.size()-1);
		int w = findInW(e,0,W.size()-1);
		duration.insert(w-v+1);
		//cout<<"s="<<s<<"e="<<e<<".."<<v<<" "<<w<<"..\n";
	}
	cout<<*duration.begin()<<endl;

	return 0;
}