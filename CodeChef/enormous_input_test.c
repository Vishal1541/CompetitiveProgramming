#include<stdio.h>
int main(){
    int n,k,num,i,c=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        if(!(num%k))    c++;
    }
    printf("%d",c);
    return 0;
}
