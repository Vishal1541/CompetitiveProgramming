#include <stdio.h>
#include <math.h>
#define Int long long int
#define fl(i,x,y) for(int i=x; i<y; i++)

Int raiseToPow(Int x, Int y)
{
    Int res = 1;     // Initialize result
  
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;
  
        // n must be even now
        y /= 2; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}

int main(){
	Int l,r,num,ans = 0;
    scanf("%I64d %I64d",&l,&r);
    fl(i,0,32){
        fl(j,0,21){
            num = raiseToPow(2,i)*raiseToPow(3,j);
            if(num>2*1000000000){
                break;
            }
            if(l<=num && num<=r)    ans++;
        }
    }
    printf("%I64d \n", ans);

	return 0;
}