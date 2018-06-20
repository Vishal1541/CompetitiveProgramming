#include <stdio.h>

long long int T, U, V;

int main(){
	scanf("%lld",&T);
	int i;
	for(i=0; i<T; i++){
		scanf("%lld %lld",&U,&V);
		if(U==0 && V==0)
			printf("1\n");
		/*else if(U==0 && V!=0){
			int yRank = 1, incrementYValue = 1;
			int k;
			for(k=0; k<V; k++){
				yRank = yRank + incrementYValue;
				incrementYValue++;
			}
			printf("%d\n",yRank);
		}
		else if(U!=0 && V==0){
			int xRank = 1, incrementXValue = 2;
			int k;
			for(k=0; k<U; k++){
				xRank = xRank + incrementXValue;
				incrementXValue++;
			}
			printf("%d\n",xRank);
		}
		*/
		/*else{
			int R0 = 1, n = 0;
			while(U != 0){
				U--;
				V++;
				n++;
			}
			int k, increment = 1;
			for(k=0; k<V; k++){
				R0 = R0 + increment;
				increment++;
			}
			int rankMax = R0 + n;
			printf("%d\n",rankMax);
		}*/
		else{
			long long int n = U;
			U = 0;
			V = V + n;
			long long int yRank = V*(V+1)/2 + 1;
			long long int rankMax = yRank + n;
			printf("%lld\n",rankMax);
		}
	}

	return 0;
}