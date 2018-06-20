#include <stdio.h>
#define MODULO 1000000007
unsigned long long int T, p ,q, r;

void mergeSort(unsigned long long int d[],unsigned long long  int l,unsigned long long  int u){
	unsigned long long int m = (l+u)/2,i;
	if(l<u){
		mergeSort(d,l,m);
		mergeSort(d,m+1,u);
		merge(d,l,m,u);
	}
}

void merge(unsigned long long int d[], unsigned long long int l, unsigned long long int m, unsigned long long int u){
	unsigned long long int p1 = l, p2 = m+1;
	unsigned long long int r[u-l+2];
	unsigned long long int i=0,k,x;
	while(!(p1==(m+1) || p2==(u+1) )){
		if(d[p1] < d[p2])	r[i++] = d[p1++];
		else				r[i++] = d[p2++];
	}
	if(p1==m+1)
		for(k=p2;k<=u;k++)		r[i++] = d[k];
	else
		for(k=p1;k<=m;k++)		r[i++] = d[k];
	i=0;
	for(x=l;x<=u;x++)			d[x] = r[i++];
}
/*
void mergeSortDesc(unsigned long long int d[],unsigned long long  int l,unsigned long long  int u){
	unsigned long long int m = (l+u)/2,i;
	if(l<u){
		mergeSortDesc(d,l,m);
		mergeSortDesc(d,m+1,u);
		mergeDesc(d,l,m,u);
	}
}

void mergeDesc(unsigned long long int d[], unsigned long long int l, unsigned long long int m, unsigned long long int u){
	unsigned long long int p1 = l, p2 = m+1;
	unsigned long long int r[u-l+2];
	unsigned long long int i=0,k,x;
	while(!(p1==(m+1) || p2==(u+1) )){
		if(d[p1] > d[p2])	r[i++] = d[p1++];
		else				r[i++] = d[p2++];
	}
	if(p1==m+1)
		for(k=p2;k<=u;k++)		r[i++] = d[k];
	else
		for(k=p1;k<=m;k++)		r[i++] = d[k];
	i=0;
	for(x=l;x<=u;x++)			d[x] = r[i++];
}
*/


int main(){
	scanf("%llu",&T);
	int i;
	for(i=0; i<T; i++){
		unsigned long long int sum = 0;
		scanf("%llu %llu %llu",&p,&q,&r);
		unsigned long long int A[p], B[q], C[r];
		int visitedX[p], visitedZ[r];
		unsigned long long int k;
		for(k=0; k<p; k++){
			scanf("%llu",&A[k]);
			visitedX[k] = 0;
		}
		for(k=0; k<q; k++)
			scanf("%llu",&B[k]);
		for(k=0; k<r; k++){
			scanf("%llu",&C[k]);
			visitedZ[k] = 0;
		}
		mergeSort(A, 0, p-1);
		mergeSort(B, 0, q-1);
		mergeSort(C, 0, r-1);
		unsigned long long int a,b,c;
		unsigned long long int X,Y,Z;

		/*int YtoX[q], YtoZ[q];
		YtoX[0] = 0;
		YtoZ[0] = 0;
		*/
		int YtoX=0, YtoZ=0;
		int YtoX_PRV=0, YtoZ_PRV=0;

		unsigned long long int XY = 0, Y2 = 0, XZ = 0, YZ = 0, sumX = 0, sumZ = 0;

		sumX = 0;
		sumZ = 0;
		a=0;
		c=0;
		X = A[0];
		Z = C[0];
		for(b=0; b<q; b++){
			Y = B[b];
			if( !(Y>=X && Y>=Z) )
				continue;
			while(a<p && Y>=A[a]){
				if(!visitedX[a]){
					X = A[a];
					visitedX[a] = 1;
					sumX = (sumX + X)%MODULO;
					YtoX++;
				}
				a++;
				if(a==p)
					break;
			}
			if(a!=p)
				a--;

			while(c<r && Y>=C[c]){
				if(!visitedZ[c]){
					Z = C[c];
					visitedZ[c] = 1;
					sumZ = (sumZ + Z)%MODULO;
					YtoZ++;
				}
				c++;
				if(c==r)
					break;
			}
			if(c!=r){
				c--;
			}
			Y2=0;
			Y2 = ((Y%MODULO)*(Y%MODULO))%MODULO;

			unsigned long long int Part1=0, Part2=0, Part3=0, Part4=0;
 
			Part1 = ( (Y2%MODULO) * (YtoX%MODULO) * (YtoZ%MODULO) ) % MODULO;
			Part2 = ( (YtoZ%MODULO) * sumX%MODULO ) % MODULO;
			Part3 = ( (YtoX%MODULO) * sumZ%MODULO ) % MODULO;
			Part4 = ( (sumX%MODULO) * (sumZ%MODULO) ) % MODULO;
 
			sum = sum + Part1 + ( ((Part2%MODULO) + (Part3%MODULO)) * Y%MODULO ) % MODULO + Part4;
 
			sum = sum % MODULO;

		}

		/*
		for(b=0 ;b<q; b++){
			Y = B[b];
			//X = A[a];
			//Z = C[c];
			if(Y<X || Y<Z){
				continue;
			}
			if(a<p){
				while(Y>=X){
					sumX = (sumX + X)%MODULO;
					YtoX++;
					a++;
					if(a==p){
						break;
					}
					else
						X = A[a];
				}
			}
			YtoX_PRV = YtoX;

			if(c<r){
				while(Y>=Z){
					sumZ = (sumZ + Z)%MODULO;
					YtoZ++;
					c++;
					if(c==r){
						break;
					}
					else
						Z = C[c];
				}
			}
			YtoZ_PRV = YtoZ;

			Y2 = ((Y%MODULO)*(Y%MODULO))%MODULO;
			//sum = sum + ((Y2%MODULO)*(YtoX[b]%MODULO)*(YtoZ[b]%MODULO))%MODULO + ( (YtoZ[b]*(sumX%MODULO))%MODULO + ((YtoX[b]/MODULO)*(sumZ%MODULO))%MODULO + ((sumX%MODULO)*(sumZ%MODULO))%MODULO;
 
			unsigned long long int Part1=0, Part2=0, Part3=0, Part4=0;
 
			Part1 = ( (Y2%MODULO) * (YtoX%MODULO) * (YtoZ%MODULO) ) % MODULO;
			Part2 = ( (YtoZ%MODULO) * sumX%MODULO ) % MODULO;
			Part3 = ( (YtoX%MODULO) * sumZ%MODULO ) % MODULO;
			Part4 = ( (sumX%MODULO) * (sumZ%MODULO) ) % MODULO;
 
			sum = sum + Part1 + ( ((Part2%MODULO) + (Part3%MODULO)) * Y%MODULO ) % MODULO + Part4;
 
			sum = sum % MODULO;
		}
		*/
		
		sum = sum % MODULO;
		printf("%llu\n",sum);
	}

	return 0;
}