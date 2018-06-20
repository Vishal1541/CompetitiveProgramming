//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

class DevuAndEqualizingLCM
{
private:
	long long int lcmA;
	int ans;
public:
	int minimumOperationsNeeded(vector<long long> A, vector<long long> B){
		lcmA = 1;
		ans = 0;
		for(int i=0; i<A.size(); i++){
			lcmA = lcm(lcmA,A[i]);
		}
		for(int i=0; i<B.size(); i++){
			if(lcmA%B[i]!=0){
				ans++;
			}
		}
		return ans;
	}
};