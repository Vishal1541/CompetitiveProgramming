#include<stdio.h>
int isRepeated(int ch[],int n){
	int i,j;
	for(i=0;i<n;i++){
		if(i==n-1)
			return 0;
		for(j=n-1;j>i;j--){
			if(ch[i]==ch[j])
				return 1;
		}
	}
}
int isArrangedCorrectly(int ch[],int n){
	int i=0,actual_sum=0,array_sum=0;
	while(i<n-1){
		if(ch[i+1]==ch[i]+1)	i++;
		else break;
	}
	if(i==n-1)
		return 0;
	for(i=1;i<=n;i++)
		actual_sum+=i;
	for(i=0;i<n;i++)
		array_sum+=ch[i];
	if(actual_sum==array_sum)
		return 1;
	else
		return 0;
}
int main(){
	int T,i,j,n;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d",&n);
		int chapter[n];
		for(j=0;j<n;j++){
			scanf("%d",&chapter[i]);
		}
		int is_repeated = isRepeated(chapter,n);
		int is_arranged_correctly = isArrangedCorrectly(chapter,n);
		if(is_repeated==1)
			printf("no\n");
		else if(is_arranged_correctly==1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
