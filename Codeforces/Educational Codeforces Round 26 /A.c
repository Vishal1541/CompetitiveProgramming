#include <stdio.h>
#include <stdlib.h>

int main(){
	char *n=malloc(100);
	fgets(n,100,stdin);
	char *str = malloc(300);
	fgets(str,300,stdin);
	int Max=-1, temp;
	int i=0;
	while(str[i]!='\n'){
		char ch=str[i];
		temp=0;
		while(ch!=' ' && ch!='\n'){
			if(ch>='A' && ch<='Z')	temp++;
			i++;
			ch = str[i];
		}
		if(temp>Max)	Max=temp;
		if(ch=='\n')	break;
		i++;	
	}
	printf("%d\n",Max);

	return 0;
}