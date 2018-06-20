#include <iostream>
#include <cstdio>

using namespace std;

int T,len;
string str;

int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		cin>>str;
		len = str.length();
		int s_len=0, m_len=0;
		for(int j=0; j<len; j++){
			if(str[j]=='s')
				s_len++;
			else if(str[j]=='m'){
				m_len++;
				if(j>0){
					if(str[j-1]=='s' && str[j+1]!='s'){
						str[j-1]='x';
						s_len--;
						continue;
					}
				}
				if(j<len-1){
					if(str[j-1]!='s' && str[j+1]=='s'){
						str[j+1]='x';
						continue;
					}
				}
				if(j>0 && j<len-1){
					if(str[j-1]=='s' && str[j+1]=='s'){
						str[j-1]='x';
						s_len--;
						continue;
					}
				}
			}
		}
		if(s_len > m_len)
			printf("snakes\n");
		else if(s_len < m_len)
			printf("mongooses\n");
		else
			printf("tie\n");

	}

	return 0;
}