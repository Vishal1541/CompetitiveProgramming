#include<stdio.h>
int main(){
    int T,i,j;
    long int C,D,L;
    int app_C;
    int max_leg,min_leg;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%ld%ld%ld",&C,&D,&L);
        app_C = C;
        max_leg = 4*(C+D);
        for(j=0;j<D;j++){
            if(app_C-2<0)
                app_C--;
            else
                app_C-=2;
        }
        min_leg = 4*(app_C+D);
        if(L>=min_leg && L<=max_leg && L%4==0)
            printf("yes");
        else
            printf("no");
    }
    return 0;
}
