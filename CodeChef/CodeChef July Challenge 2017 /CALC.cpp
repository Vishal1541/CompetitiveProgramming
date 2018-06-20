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
#include <queue>
#include <functional>

using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
#define Int unsigned long long int

Int T,N,B;

int main(){
	ios;
	cin>>T;while(T--){
		cin>>N>>B;
		if(B>N){
			cout<<"0\n"; continue;
		}
		Int b2_bottom = N/B;
		Int b1_bottom = N-b2_bottom*B;
		Int b2_mid = b2_bottom/2;
		Int diff = b2_bottom - b2_mid;
		Int b1_mid = b1_bottom + diff*B;
		Int MAX = b1_mid*b2_mid;
		Int MAX_temp=MAX, b1_mid_temp=b1_mid, b2_mid_temp=b2_mid;
		if(b2_bottom==1){
			cout<<N-B<<endl; continue;
		}
		while(b2_mid_temp>=1 && b2_mid_temp<=b2_bottom){
			b2_mid_temp--, b1_mid_temp += B;
			MAX_temp = b1_mid_temp*b2_mid_temp;
			if(MAX_temp>MAX){
				MAX = MAX_temp; continue;
			}
			break;
		}
		b1_mid_temp=b1_mid, b2_mid_temp=b2_mid;
		while(b2_mid_temp>=1 && b2_mid_temp<=b2_bottom){
			b2_mid_temp++, b1_mid_temp -= B;
			MAX_temp = b1_mid_temp*b2_mid_temp;
			if(MAX_temp>MAX){
				MAX = MAX_temp; continue;
			}
			break;
		}
		cout<<MAX<<endl;
	}

	return 0;
}