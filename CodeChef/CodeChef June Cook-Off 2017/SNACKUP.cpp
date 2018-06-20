#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

typedef long long int lli;
using namespace std;
int T, n;
int b = 1, f = 2;

/*lli nCr( lli n, lli k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    lli result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
*/
void findCombEven(int pair[2], int n){
	pair[0] = b;
	pair[1] = f;
	f += 2;
	b += 2;
}

void findCombOdd(int pair[2], int n){
	pair[0] = b;
	pair[1] = f;
	if(f==n)
		b = 1;
	else{
		b++;
		f++;
	}
}


int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int pair[2] = {0,0};
		printf("%d\n", n);
		if(n%2==0){
			for(int i=0; i<2; i++){
				b = 1;
				f = 2;
				for(int j=0; j<n/2; j++){
					printf("%d\n",n);
					findCombEven(pair, n);
					for(int k=0; k<n; k++){
						printf("%d %d %d\n",k+1,pair[0],pair[1]);
					}
				}
			}
		}
		else{
			b = 1;
			f = 2;
			for(int i=0; i<n ;i++){
				printf("%d\n",n);
				findCombOdd(pair, n);
				for(int k=0; k<n; k++){
					printf("%d %d %d\n",k+1,pair[0],pair[1]);
				}
			}
		}
	}

	return 0;
}