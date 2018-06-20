//    VISHAL ANAND
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
#define sort(v) sort(v.begin(),v.end());
#define PI 3.141592653589793238L
#define F first
#define S second
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define make_pair mp

int T;

int main(){
	cin>>T;
	while(T--){
		string str;
		cin>>str;
		Int seconds = 0;
		int no_of_1 = 0, no_of_0 = 0;
		bool last_zero = false;
		fl(i,0,str.length()){
			if(str[i]=='1'){	
				no_of_1++;
				i++;
			
				while(str[i]=='0'){
					no_of_0++;
					i++;
				}
				if(no_of_0>0) seconds += no_of_1*(no_of_0+1);
				i--;
				no_of_0 = 0;
			}
		}
		cout<<seconds<<endl;
	}

	return 0;
}