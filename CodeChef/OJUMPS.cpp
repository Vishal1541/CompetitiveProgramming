#include<iostream>
#include<cstdio>
using namespace std;
long long int a;
int main(){
    scanf("%lld",&a);
    long long int MOD = a%6;
    switch(MOD){
        case 0:
        case 1:
        case 3: printf("yes\n"); break;
        default: printf("no\n");break;
    }
    
    return 0;
}