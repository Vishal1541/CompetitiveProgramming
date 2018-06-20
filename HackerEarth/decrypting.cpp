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
	vi arr;
	fl(i,0,N){
		int in;
		cin>>in;
		arr.pb(in);
	}
	sort(arr.begin(), arr.end());
	while(Q--){
		int X;
		cin>>X;
		if(isPrime(X)){
			cout<<"NO\n";
			continue;
		}
		const int TOTAL_FACTORS = findTotalFactors(X);
		if(TOTAL_FACTORS==2){
			cout<<"YES\n";
			continue;
		}
		//cout<<"TOTAL_FACTORS = "<<TOTAL_FACTORS<<endl;
		bool yes=false;
		fl(i,0,N){
			int divisor = arr[i];
			if(divisor==0 || divisor==1)
				continue;
			//cout<<"divisor "<<divisor<<endl;
			int temp_X = X;
			//if(temp_X%divisor!=0)
			//	break;
			while(temp_X%divisor==0)
				temp_X /= divisor;
			int TOTAL_FACTORS_TEMP = findTotalFactors(temp_X);
			//cout<<"temp_X = "<<temp_X<<"TOTAL_FACTORS_TEMP = "<<TOTAL_FACTORS_TEMP<<endl;
			if(TOTAL_FACTORS_TEMP <= 2){
				yes = true;
				break;
			}
		}
		if(yes)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}