#include <stdio.h>
#include <stdlib.h>
void to_upper(char *c){
	if(*c>='a' && *c<='z')
		*c -= 32;
}

void to_lower(char *c){
	if(*c>='A' && *c<='Z')
		*c += 32;
}
void printall(char *n[3],int i){
	int j=0;
	while(n[i][j++]!='\0')
		printf("%c",n[i][j-1]);
	printf("\n");
}
int main(){
	int T;
	scanf("%d\n",&T);
	while(T--){
		char in;
		scanf("%c",&in);
		char *n[3];
		n[0] = malloc(100);
		n[1] = malloc(100);
		n[2] = malloc(100);
		int c=1,p=0;
		to_upper(&in);
		while(in!='\n'){
			n[c-1][p++]=in;
			scanf("%c",&in);
			if(in==' '){
				n[c-1][p++]='\0';
				p=0,c++;
				scanf("%c",&in);
				to_upper(&in);
				continue;
			}
			if(in=='\n')	break;
			to_lower(&in);
		}
		n[c-1][p++]='\0';
		if(c==1)
			printall(n,0);
		else if(c==2){
			printf("%c. ",n[0][0] );
			printall(n,1);
		}
		else{
			printf("%c. %c. ",n[0][0],n[1][0] );
			printall(n,2);
		}
	}

	return 0;
}