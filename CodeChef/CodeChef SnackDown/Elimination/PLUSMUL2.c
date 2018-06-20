#include <stdio.h>
#define MODULO 1000000007

int T, n;
unsigned long long int sum;
int arrNum[100000];

int power(int x, int y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}

int main(){
    scanf("%d",&T);
    int i;
    for(i=0; i<T; i++){
        sum = 0;
        scanf("%d",&n);
        int j;
        for(j=0; j<n; j++)
            scanf("%d",&arrNum[j]);
        if(n==1){
            printf("%d\n",arrNum[0]);
            continue;
        }
        int N = n-1;
        int exp = 0;
        for(j=0; j<n; j++)
            sum += arrNum[j];
        while(N!=0){
            int mul = 1, add = 0;
            for(j=0; j<n-N+1; j++){
                int k;
                mul = arrNum[j];
                for(k=1; k<N; k++){
                    mul = mul * arrNum[j+k];
                }
                mul = mul * power(2,exp);
                add = add + mul;
            }
            N--;
            exp++;
            sum = sum + add;
            sum = sum % MODULO;
        }
        int mul = arrNum[0];
        for(j=1; j<n; j++)
            mul = mul * arrNum[j];
        sum = sum + mul;
        sum = sum % MODULO;
        printf("%llu\n",sum);
    }
    return 0;
}