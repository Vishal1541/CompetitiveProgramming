#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define si set<Int>
#define si_d set<Int, greater<Int> >
#define pb push_back
#define MOD 1e9+7

int N;

int main(){
	cin>>N;
	vi arr(N), arr2(N);
	bool zero_found = false;
	fl(i,0,N){
		Int in;
		scanf("%lld",&in);
		if(in==0)
			zero_found = true;
		arr[i]=in;
	}
	if(N==1){
		cout<<arr[0];
		return 0;
	}
	if(zero_found==false){
		cout<<N;
		return 0;
	}
	int NO_OF_ONES = 0, NO_OF_ONES_TEMP = 0;
	copy(arr.begin(),arr.end(),arr2.begin());
	fl(i,0,N){
		if(arr2[i]==0){
			fl(j,0,N){
				if(arr2[j]==1){
					swap(arr2[i],arr2[j]);
					fl(k,0,N){
						NO_OF_ONES_TEMP = 0;
						while(arr2[k]==1){
							NO_OF_ONES_TEMP++;
							k++;
							if(k==N)
								break;
						}
						if(NO_OF_ONES_TEMP > NO_OF_ONES)
							NO_OF_ONES = NO_OF_ONES_TEMP;
					}
					copy(arr.begin(),arr.end(),arr2.begin());
				}
			}
		}
	}
	cout<<NO_OF_ONES;

	return 0;
}