#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

void checkSnake(int row, int col, int direction, int m[2][n], int visited[2][n]){
	visited[row][col] = 1;
	if(m[row][col]==0){
		if(direction==1)
			checkSnake(1,col,2,m,visited);
		else if(direction==2){
			if(row==0)
				checkSnake(row,col+1,1,m,visited);
			else
				checkSnake(row,col+1,3,m,visited);
		}
		else
			checkSnake(0,col,2,m,visited);
	}
	else{
		if(direction==1){
			if(m[1][col]==0){
				visited[1][col] = 1;
				if(col!=n-1){
					if(m[0][col+1]==0){
						visited[0][col+1] = 1;
						return;
					}
					else
						checkSnake(0,col+1,1,m,visited);
				}
				else
					return;
			}
			else{
				checkSnake(1,col,2,m,visited);
			}
		}
		else if(direction==2){
			if(col!=n-1){
				if(m[row][col+1]==0){
					visited[row][col+1] = 1;
					return;
				}
				else{
					if(row==0)
						checkSnake(0,col+1,1,m,visited);
					else{
						checkSnake(1,col+1,3,m,visited);
					}
				}
			}
			else
				return;
		}
		else{
			if(m[0][col]==0){
				visited[0][col] = 1;
				if(col!=n-1){
					if(m[1][col+1]==0){
						visited[1][col+1] = 1;
						return;
					}
					else
						checkSnake(1,col+1,3,m,visited);
				}
				else
					return;
			}
			else{
				checkSnake(0,col,2,m,visited);
			}
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		scanf("%d",&n);
		int m[2][n];
		int j,k;
		char* a = malloc(n+2);
		for(j=0; j<2; j++){
			scanf("%s",a);
			for(k=0; k<n; k++){
				if(a[k]=='#')
					m[j][k] = 1;
				else 
					m[j][k] = 0;
			}
		}
		/*printf("\n");
		for(j=0; j<2; j++){
			for(k=0; k<n; k++)
				printf("%d", m[j][k]);
			printf("\n");
		}
		*/
		int visited[2][n];
		for(j=0; j<2; j++)
			for(k=0; k<n; k++)
				visited[j][k] = 0;
		checkSnake(0,0,1,m,visited);


		/*for(j=0; j<2; j++){
			for(k=0; k<n; k++)
				printf("%d  ",visited[j][k]);
			printf("\n");
		}
		*/
		int c=0;
		for(j=0; j<2; j++){
			for(k=0; k<n; k++){
				if(visited[j][k]==0 && m[j][k]==1){
					c=1;
					break;
				}
			}
		}
		if(c==0)
			printf("yes\n");
		else{
			for(j=0; j<2; j++)
				for(k=0; k<n; k++)
					visited[j][k] = 0;
			checkSnake(1,0,3,m,visited);


			/*printf("\n");
			for(j=0; j<2; j++){
			for(k=0; k<n; k++)
				printf("%d  ",visited[j][k]);
			printf("\n");
			}
			*/
			int d=0;
			for(j=0; j<2; j++){
				for(k=0; k<n; k++){
					if(visited[j][k]==0 && m[j][k]==1){
						d=1;
						break;
					}
				}
			}
			if(d==0)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}