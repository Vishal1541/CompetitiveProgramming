#include <stdio.h>

int T, n, m;
int MAXALL = 0;
int TOTAL_MAX_NUMBERS = 0;

/*void init(int a[n][m]){
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			a[i][j] = 0;
}
*/
int getMax(int a[n][m], int i, int j){
	int max = a[i][j];
	if(isValid(i-1,j) && (a[i-1][j] > max)){
			max = a[i-1][j];
	}
	if(isValid(i-1,j+1) && (a[i-1][j+1] > max)){
			max = a[i-1][j+1];
	}
	if(isValid(i,j+1) && (a[i][j+1] > max)){
			max = a[i][j+1];
	}
	if(isValid(i+1,j+1) && (a[i+1][j+1] > max)){
			max = a[i+1][j+1];
	}
	if(isValid(i+1,j) && (a[i+1][j] > max)){
			max = a[i+1][j];
	}
	if(isValid(i+1,j-1) && (a[i+1][j-1] > max)){
			max = a[i+1][j-1];
	}
	if(isValid(i,j-1) && (a[i][j-1] > max)){
			max = a[i][j-1];
	}
	if(isValid(i-1,j-1) && (a[i-1][j-1] > max)){
			max = a[i-1][j-1];
	}
	return max;
}

int isValid(int i, int j){
	if(i>=0 && j>=0 && i<n && j<m)
		return 1;
	else
		return 0;
}

/*int isAllEqual(int a[n][m]){
	int val = a[0][0];
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(a[i][j] != val)
				return 0;
		}
	}
	return 1;
}
*/
/*int isMatrixEqual(int a[n][m], int b[n][m]){
	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(a[i][j] != b[i][j])
				return 0;
	return 1;
}
*/
int getMaxValue(int a[n][m]){
	int max=0, i, j;
	TOTAL_MAX_NUMBERS = 0;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++){
			if(a[i][j] == max)
				TOTAL_MAX_NUMBERS++;
			else if(a[i][j] > max){
				TOTAL_MAX_NUMBERS = 1;
				max = a[i][j];
			}

		}
	return max;
}

int main(){
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		scanf("%d%d",&n,&m);
		int a[n][m], new[n][m];
		//init(a);
		//init(new);
		int r,c;
		int count = 0;
		int max;
		int temp=0;
		for(r=0; r<n; r++)
			for(c=0; c<m; c++){
				scanf("%d",&a[r][c]);
				new[r][c] = a[r][c];
			}
		TOTAL_MAX_NUMBERS = 0;
		MAXALL = getMaxValue(a);
		int nm = n*m;
		while(TOTAL_MAX_NUMBERS < nm){
			for(r=0; r<n; r++){
				for(c=0; c<m; c++){
					if(a[r][c] < MAXALL){
						max = getMax(a,r,c);
						new[r][c] = max;
						if(max==MAXALL)
							TOTAL_MAX_NUMBERS++;
						temp = 1;
					}
					//printf("\n%d\n", new[r][c]);
				}
			}
			if(temp == 1)
				count++;
			temp = 0;
			for(r=0; r<n; r++){
				for(c=0; c<m; c++){
					a[r][c] = new[r][c];
				}
			}
		}
		printf("%d\n",count);
	}

	return 0;
}