#include <stdio.h>
#include <math.h>
#define LIMIT 1000000
int N, Q, L, R, X, Y;

//int primeNo[LIMIT], primeNoIndex[LIMIT];

/*int isPrime(int NUM)
{
	int i;
	if (NUM <= 1) return 0;
	if (NUM % 2 == 0 && NUM > 2) return 0;
	for(i = 3; i < NUM / 2; i+= 2){
	    if (NUM % i == 0)
	        return 0;
	}
	return 1;
}
*/

/*int isPrime(int NUM){
	if(NUM <=1)
		return 0;
	if(NUM==2 || NUM==3)
		return 1;
	int index = primeNoIndex[NUM];
	if(index!=0)
		return 1;
	else
		return 0;
}
*/
/*void primeFactors(int n)
{
    // Print the number of 2s that divide n
    int T = n;
    int index = 0;
    if(n%2==0){
    	primeNo[index] = 2;
    	primeNoIndex[2] = index;
    	occurrance[index] = 0;
	    while (n%2 == 0)
	    {
	        occurrance[index]++;
	        n = n/2;
	    }
 	}
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    int i;
    for (i = 3; i <= sqrt(T); i = i+2){
    	index++;
    	primeNo[index] = i;
    	primeNoIndex[i] = index;
    	occurrance[index] = 0;
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            occurrance[index]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    //if (n > 2)
    //   printf ("%d ", n);
}
*/

void primeFactors(unsigned long long int n, unsigned long long int occurrance[LIMIT]){
	occurrance[0]=0;
	occurrance[1]=0;
	unsigned long long int i;
	unsigned long long int index=0;
	unsigned long long int initVal = n;
	for (i = 2; i <= n; ++i) // for each number i up until the square root of the given number
	{
	    //power = 0; // suppose the power i appears at is 0
	    while (n % i == 0) // while we can divide n by i
	    {
	    	//primeNo[index] = i;
	    	occurrance[i]++;
	        n = n / i; // divide it, thus ensuring we'll only check prime factors
	        //++power // increase the power i appears at
	    }
	    if(n==1)
	    	break;
	    //num_factors = num_factors * (power + 1) // apply the formula
	}

	/*if (n > 1) // will happen for example for 14 = 2 * 7
	{
	    //num_factors = num_factors * 2 // n is prime, and its power can only be 1, so multiply the number of factors by 2
	    //primeNo[index] = n;
	    occurrance[n]++;
	}
	*/
}
int main(){
	//primeNoIndex[0] = -1;
	scanf("%d",&N);
	int a[N];
	int i;
	for(i=0; i<N; i++)
		scanf("%d",&a[i]);
	scanf("%d",&Q);
	for(i=0; i<Q; i++){
		scanf("%d %d %d %d",&L,&R,&X,&Y);
		L--;
		R--;
		int l=0;;
		unsigned long long int num=1;
		unsigned long long int occurrance[LIMIT] = {0};
		int counter = 0;
		int br = 0;
		for(l=L; l<=R; l++){
			//num = num * a[l];
			//prod *= a[l];
			br = 0;
			if(counter!=3){
				num = num*a[l];
				counter++;
			}
			if(counter==3){
				primeFactors(num, occurrance);
				counter = 0;
				num = 1;
				br = 1;
			}
		}
		//primeFactors(num, occurrance);
		if(br==0)
			primeFactors(num, occurrance);
		/*printf("\n");
		int m;
		for(m=0; m<4; m++){
			printf(" %d ",primeNo[m]);
		}
		printf("\n");
		for(m=0; m<8; m++){
			printf(" %d ",primeNoIndex[m]);
		}
		printf("\n");
		for(m=0; m<4; m++){
			printf(" %d ",occurrance[m]);
		}
		printf("\n");
		*/
		int j;
		int ans = 0;
		for(j=X; j<=Y; j++){
				ans += occurrance[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}





/*int isPrime(int n){
    int i;

    if (n==2)
        return 1;

    if (n%2==0)
        return 0;

    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;

    return 1;
}

int F(int prod, int X, int Y, int a[N]){
	int result = 0;
	int i;
	for(i=X; i<=Y; i++){
		if(isPrime(i)){
			int j;
			int exponent = 0;
			while(prod % i == 0){
				exponent++;
				prod = prod / i;
			}
			result = result + exponent;
		}
	}
	return result;
}
*/