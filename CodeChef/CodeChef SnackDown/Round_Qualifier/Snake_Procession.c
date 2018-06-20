#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isComplement(char a, char b){
	if(a=='H' && b=='T')
		return 1;
	return 0;
}

int isHT(char a){
	if(a=='H' || a=='T')
		return 1;
	return 0;
}

int main(){
	
	int R, L, i, j;
	scanf("%d",&R);
	char *string = malloc(500);
	for (i = 0; i < R; ++i)
	{
		scanf("%d",&L);
		scanf("%s",string);
		char a='X', b='X';
		int Switch=0;
		for (j = 0; j < L; ++j)
		{
			if(Switch==0 && isHT(string[j])){
				a = string[j];
				Switch = 1;
			}
			else if(Switch==1 && isHT(string[j])){
				b = string[j];
				Switch = 0;
			}
			if(isHT(a) && isHT(b)){
				if(isComplement(a,b)){
					a='X';
					b='X';
				}
				else
					break;
			}
		}
		if(a=='X' && b=='X')
			printf("Valid\n");
		else if(isComplement(a,b))
			printf("Valid\n");
		else
			printf("Invalid\n");
	}
	
	return 0;
}