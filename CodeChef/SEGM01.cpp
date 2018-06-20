#include <iostream>
#include <cstdio>

using namespace std;

int T;
string str;

int main(){
	scanf("%d",&T);
	while(T--){
		cin>>str;
		int len = str.length();
		int flag = 0;
		int one_segment_found = 0, another_segment_found = 0;
		for(int i=0; i<len; i++){
			char ch = str[i];
			if(ch=='1' && flag == 0){
				flag = 1;
			}
			else if(ch=='0' && flag==1 && one_segment_found==0){
				one_segment_found = 1;
			}
			else if(ch=='1' && one_segment_found==1){
				another_segment_found = 1;
				break;
			}
		}
		if(flag==1)
			one_segment_found = 1;
		if(flag==0 || another_segment_found==1 || one_segment_found==0)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}