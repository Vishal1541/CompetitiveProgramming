#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int main(){
    int T,N,i,j;
    int lower=0,upper,c=0;
    int k=0,w=0;
    scanf("%d",&T);
    assert(T>=1 && T<=500);
    for(i=1;i<=T;i++){
        scanf("%d",&N);
        assert(N>=1 && N<=100);
        int W[N];
        for(j=0;j<N;j++){
            scanf("%d",&W[j]);
        }
        qsort(W,N,sizeof(int),cmpfunc);
        upper = N-1;
        while(1){
            w=W[upper];
            k=1;
            while(k*w<50 && lower<upper){
                k++;
                lower++;
            }
            upper--;
            c++;
            if(lower>=upper)
                break;
        }
        printf("Case #%d: %d",i,c);
        c=0;
        lower=0;
        w=0;
    }
    return 0;
}
