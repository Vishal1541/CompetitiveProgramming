#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int T;
string str;

int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		cin>>str;
		int len = str.length();
		vector<int> plus_first(len,0);
		vector<int> minus_first(len,0);
		int plus_count = len;
		int minus_count = len;
		for(int i=0; i<len; i++){
			if( (i%2==0 && str[i]=='+') || (i%2==1 && str[i]=='-') )
				plus_count--;
			if( (i%2==0 && str[i]=='-') || (i%2==1 && str[i]=='+') )
				minus_count--;
		}
		printf("%d\n",min(plus_count,minus_count));
	}

	return 0;
}