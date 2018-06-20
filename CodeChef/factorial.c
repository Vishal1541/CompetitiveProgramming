#include<stdio.h>
int Fact(int n){
    int f=1,i;
    for(i=1;i<=n;i++)
        f*=i;
    return f;
}
int ZofN(int n){
    int z=0;
    while(n%10==0){
        z++;
        n/=10;
    }
    return z;
}
int main(){
    int Z,T,N,i;
    long long int F;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        F = Fact(N);
        Z = ZofN(F);
        printf("%d\n",Z);
    }
    return 0;
}
