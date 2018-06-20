#include<stdio.h>
int main(){
    int withd;
    float bal_before,bal_after;
    scanf("%d",&withd);
    scanf("%f",&bal_before);
    bal_after=bal_before-withd-0.5;
    if(bal_after>=0 && withd%5==0){
        printf("%.2f",bal_after);
    }
    else{
        printf("%.2f",bal_before);
    }
    return 0;
}
