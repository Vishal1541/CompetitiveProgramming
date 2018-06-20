#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long T;
long N, K, M;
long HX, HY, TX, TY;

void initMatrix(char m[M][K]){
	int i,j;
	for(i=0; i<M; i++)
		for(j=0; j<K; j++)
			m[i][j] = '0';
}

void makeAllFlagZero(char f[], long A){
	long i;
	for(i=0; i<A; i++)
		f[i] = '0';
}

long isVisitedAll(char f[], long A){
	long i,c=0;
	for(i=0; i<A; i++){
		if(f[i]=='0'){
			c=1;
			break;
		}
	}
	if(c==1)
		return 0;
	else
		return 1;
}

long main(){
	scanf("%ld",&T);
	long i;
	for(i=0; i<T; i++){
		scanf("%ld %ld %ld",&N,&K,&M);
		char rows[M][K], col[M][K];
		initMatrix(rows);
		initMatrix(col);
		long topleftK = (N-K)/2;
		long j;
		for(j=0; j<M; j++){
			scanf("%ld %ld %ld %ld",&HX,&HY,&TX,&TY);
			HX--;
			HY--;
			TX--;
			TY--;
			if(HX==TX){
				if( HX >= topleftK && HX < N-topleftK){
					rows[j][HX-topleftK] = '1';	
				}
				else{
					long k;
					for(k=HY; k<=TY; k++){
						if( k >= topleftK && k < N-topleftK ){
							col[j][k-topleftK] = '1';
						}
					}
					for(k=TY; k<=HY; k++){
						if( k >= topleftK && k < N-topleftK ){
							col[j][k-topleftK] = '1';
						}
					}
				}
			}
			else if(HY==TY){
				if( HY >= topleftK && HY < N-topleftK ){
					col[j][HY-topleftK] = '1';
				}
				else{
					long k;
					for(k=HX; k<=TX; k++){
						if( k >= topleftK && k < N-topleftK ){
							rows[j][k-topleftK] = '1';
						}
					}
					for(k=TX; k<=HX; k++){
						if( k >= topleftK && k < N-topleftK ){
							rows[j][k-topleftK] = '1';
						}
					}
				}
			}
		}

		/*for (long i = 0; i < M; ++i)
		{
			for (long j = 0; j < K; ++j)
			{
				printf("%c  ",rows[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		for (long i = 0; i < M; ++i)
		{
			for (long j = 0; j < K; ++j)
			{
				printf("%c  ",col[i][j]);
			}
			printf("\n");
		}
		*/

		long c=0;
		long x;
		for(x=0; x<K; x++){
			c=0;
			long y;
			for(y=0; y<M; y++){
				if(rows[y][x]=='1'){
					c=1;
				}
			}
			if(c==0)
				break;
		}

		if(c==0){
			printf("-1\n");
			continue;
		}

		for(x=0; x<K; x++){
			c=0;
			long y;
			for(y=0; y<M; y++){
				if(col[y][x]=='1'){
					c=1;
				}
			}
			if(c==0)
				break;
		}

		if(c==0){
			printf("-1\n");
			continue;
		}

		char rows_flag[K], col_flag[K];
		makeAllFlagZero(rows_flag,K);
		makeAllFlagZero(col_flag,K);

		char snake_rows_flag[M];
		char snake_rows_count[M];
		char snake_col_flag[M];
		char snake_col_count[M];
		makeAllFlagZero(snake_rows_flag,M);
		//makeAllFlagZero(snake_rows_count,M);
		makeAllFlagZero(snake_col_flag,M);
		//makeAllFlagZero(snake_col_count,M);

		
		while(!isVisitedAll(rows_flag,K)){
			long TEMP_MAX_NO = 0, MAX_NO=0;
			long MAX_NO_SNAKE = -1;
			long y,x;
			for(y=0; y<M; y++){
				TEMP_MAX_NO = 0;
				for(x=0; x<K; x++){
					if(rows[y][x]=='1' && rows_flag[x]=='0'){
						TEMP_MAX_NO++;
					}
				}
				if(TEMP_MAX_NO > MAX_NO){
					MAX_NO = TEMP_MAX_NO;
					MAX_NO_SNAKE = y;
				}
			}
			snake_rows_flag[MAX_NO_SNAKE] = '1';
			//snake_rows_count[MAX_NO_SNAKE] = (char)MAX_NO;

			for(y=0; y<K; y++){
				if(rows[MAX_NO_SNAKE][y]=='1' && rows_flag[y]=='0'){
					rows_flag[y] = '1';
				}
			}
		}

		while(!isVisitedAll(col_flag,K)){
			long TEMP_MAX_NO = 0, MAX_NO=0;
			long MAX_NO_SNAKE = -1;
			long y,x;
			for(y=0; y<M; y++){
				TEMP_MAX_NO = 0;
				for(x=0; x<K; x++){
					if(col[y][x]=='1' && col_flag[x]=='0'){
						TEMP_MAX_NO++;
					}
				}
				if(TEMP_MAX_NO > MAX_NO){
					MAX_NO = TEMP_MAX_NO;
					MAX_NO_SNAKE = y;
				}
			}
			snake_col_flag[MAX_NO_SNAKE] = '1';
			//snake_col_count[MAX_NO_SNAKE] = MAX_NO;

			for(y=0; y<K; y++){
				if(col[MAX_NO_SNAKE][y]=='1' && col_flag[y]=='0'){
					col_flag[y] = '1';
				}
			}
		}
		long FINAL_ANS = 0;
		long z;
		for(z=0; z<M; z++){
			if(snake_rows_flag[z]=='1')
				FINAL_ANS++;
			if(snake_col_flag[z]=='1')
				FINAL_ANS++;
		}
		printf("%ld\n", FINAL_ANS);
	}

	return 0;
}