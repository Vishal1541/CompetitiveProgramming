#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char *a = "hello";
	char *b = malloc(100);
	printf("enter\n");
	fgets(b,100,stdin);
	printf("Output: %s\n", b);

	return 0;
}