#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>
typedef unsigned long long int llu;

using namespace std;
int N, Q,len=0, ANS = 0;

void find(char c[], string s[],int i){
	len++;
	int l = len;
	if(len==N){
		ANS++;
		return;
	}
	char c2 = s[i][0];
	for(int j=0; j<Q; j++){
		len = l;
		if(c[j]==c2){
			find(c,s,j);
		}
	}
}

int main(){
	cin>>N>>Q;
	string s[Q];
	char c[Q];
	for(int i=0; i<Q; i++){
		cin>>s[i];
		cin>>c[i];
	}
	for(int i=0; i<Q; i++){
		if(c[i]=='a'){
			len = 1;
			find(c,s,i);
		}
	}
	printf("%d\n",ANS);

	return 0;
}