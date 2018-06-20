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

#define Int unsigned long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define us unordered_set
#define um unordered_map
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator

Int T, N;

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		vi flag(N,0),C,W;
		si_d sum_arr;
		fl(i,0,N){
			int input;
			cin>>input;
			C.pb(input);
		}
		fl(i,0,N){
			int input;
			cin>>input;
			W.pb(input);
		}
		Int sum=0;
		int back=0, front=0;
		while(front<N){
			if(flag[C[front]]==0){
				flag[C[front]]=1;
				sum += W[front];
				front++;
				continue;
			}
			sum_arr.insert(sum);
			while(1){
				if(C[back]==C[front]){
					sum -= W[back];
					flag[C[back]] = 0;
					back++;
					break;
				}
				sum -= W[back];
				flag[C[back]] = 0;
				back++;
			}
			sum += W[front];
			flag[C[front]] = 1;
			front++;
		}
		sum_arr.insert(sum);
		cout<<*sum_arr.begin()<<endl;
	}

	return 0;
}