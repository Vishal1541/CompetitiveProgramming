#include <iostream>
#include <cstdio>

using namespace std;

string s;

void inverse(char *f){
	if (*f=='1')
		*f = '0';
	else
		*f = '1';
	return;
}

int main(){
	cin>>s;
	int len = s.length();
	int COUNT = 0;
	char flag = '1';
	for(int i=len-1; i>=0; i--){
		if(s[i]==flag){
			COUNT++;
			inverse(&flag);
		}
	}
	printf("%d\n",COUNT);

	return 0;
}