#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int T;
string str;

int main(){
	scanf("%d",&T);
	while(T--){
		cin>>str;
		int len = str.length();
		vector<int> arr(len,-1);
		int UP_COUNT = 0, DOWN_COUNT = 0;
		char prv = 'X';
		for(int i=0; i<len; i++){
			char ch = str[i];
			if(i==0){
				if(ch=='U'){
					UP_COUNT++;
					prv = 'U';
				}
				else{
					DOWN_COUNT++;
					prv = 'D';
				}
			}
			else{
				if(ch!=prv){
					if(ch=='U'){
						UP_COUNT++;
						prv = 'U';
					}
					else{
						DOWN_COUNT++;
						prv = 'D';
					}
				}
			}
		}
		int ANS = min(UP_COUNT, DOWN_COUNT);
		printf("%d\n",ANS);
	}

	return 0;
}
