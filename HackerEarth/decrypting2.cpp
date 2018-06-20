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

int TOTAL_FACTORS;

bool isPrime(int n){
	bool is_prime = true;

  	for(int i = 2; i <= n / 2; ++i){
      if(n % i == 0){
          is_prime = false;
          break;
      	}
  	}
  	return is_prime;
}

int findTotalFactors(int num){
	int ans = 0;
	int n=num;
	for(int i = 2; i <= n; ++i){
      while(n % i == 0){
          n /= i;
          ans++;
      	}
      if(n==1)
      	break;
  	}
  	return ans;
}

int main(){
	int N,Q;
	cin>>N>>Q;
	map<int,int> arr;
	map<int,int> :: iterator itr;
	fl(i,0,N){
		int in;
		cin>>in;
		itr = arr.find(in);
		if(itr!=arr.end())
			continue;
		arr.insert(pair<int,int>(in,findTotalFactors(in)));
	}
	/*for(itr=arr.begin(); itr!= arr.end(); itr++){
		cout<<itr->first<<" "<<itr->second<<"...";
	}
	cout<<endl;
	*/
	while(Q--){
		int X;
		cin>>X;
		if(X==0 || X==1){
			cout<<"NO\n";
			continue;
		}
		TOTAL_FACTORS = findTotalFactors(X);
		if(TOTAL_FACTORS==2){
			cout<<"YES\n";
			continue;
		}
		if(TOTAL_FACTORS==1){
			cout<<"NO\n";
			continue;
		}
		bool yes = false;
		for(itr=arr.begin(); itr!= arr.end(); itr++){
			int divisor = itr->first;
			if(divisor==0)
				continue;
			if(divisor>X)
				break;
			int X_factors = TOTAL_FACTORS;
			int divisor_factors = itr->second;
			int count = 0;
			int val = X;
			//cout<<"divisor "<<divisor<<" divisor_factors "<<divisor_factors<<" X "<<X<<" X_factors "<<X_factors<<endl;
			while(val%divisor==0){
				val /= divisor;
				count += divisor_factors;
				if(X_factors-count==2){
					yes = true;
					break;
				}
			}
			if(yes)
				break;
		}
		if(yes)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}