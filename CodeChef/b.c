#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *a = malloc(1000);
	fgets(a,1000,stdin);
	int i=0;
	int prv = 0;
	if(!(a[i]>='0' && a[i]<='9')){
		printf("Invalid input\n");
		return 0;
	}
	while(a[i]!='\n'){
		if((a[i]>='0' && a[i]<='9')){
			i++;
			prv = 0;
			continue;
		}
		else{
			if(prv==1){
				printf("Invalid input\n");
				return 0;
			}
			prv = 1;
			i++;
		}
	}
	if(!(a[i-1]>='0' && a[i-1]<='9')){
		printf("Invalid input\n");
		return 0;
	}
	double ans = 0, num;
	char sign = 'x';
	i = 0;
	while(a[i]!='\n'){
		if(a[i]>='0' && a[i]<='9'){
			num = a[i]-'0';
			i++;
			while(a[i]!='\n' && (a[i]>='0' && a[i]<='9')){
				num = num*10 + (a[i]-'0');
				i++;
			}
			if(sign=='-'){
				ans = ans-num;
			}
			else if(sign=='+'){
				ans = ans+num;
			}
			else if(sign=='*'){
				ans = ans*num;
			}
			else if(sign=='/'){
				ans = ans/num;
			}
			else{
				ans = num;
			}
			sign = a[i];
			if(a[i]=='\n')	break;
			i++;
		}
	}
	printf("%lf\n",ans);

	return 0;
}