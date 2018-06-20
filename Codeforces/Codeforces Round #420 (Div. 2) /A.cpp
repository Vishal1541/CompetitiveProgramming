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
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator

int N;
int arr[50][50];

int compute(int arr[][50], Int row , Int col){
	Int i,j;
	//cout<<arr[row][col]<<".....  \n";
	int ans=0;
	fl(j,0,N){
		fl(i,0,N){
			if(arr[row][j]+arr[i][col]==arr[row][col]){
				//cout<<arr[row][j]<<arr[i][col]<<arr[row][col]<<" .\n";
				ans = 1;
				break;
			}
		}
		if(ans==1)
			break;
	}
	return ans;
}

int main(){
	cin>>N;
	//int arr[N][N];
	fl(i,0,N)
		fl(j,0,N){
			int input;
			cin>>input;
			arr[i][j]=input;
		}
	if(N==1 && arr[0][0]==1){
		cout<<"Yes\n";
		return 0;
	}
	if(N==1 && arr[0][0]!=1){
		cout<<"No\n";
		return 0;
	}
	int is_sum = 1;
	fl(i,0,N){
		fl(j,0,N){
			//cout<<arr[i][j]<<"    ";
			if(arr[i][j]!=1){
				is_sum = 0;
				is_sum = compute(arr, i,j);
				//cout<<is_sum<<i<<j<<" \n\n";
				if(is_sum==0)
					break;
			}
		}
			if(is_sum==0)
				break;
	}
	if(is_sum)
		cout<<"Yes\n";
	else
		cout<<"No\n";

	return 0;
}