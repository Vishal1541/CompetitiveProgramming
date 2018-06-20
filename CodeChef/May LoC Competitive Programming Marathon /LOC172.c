#include <stdio.h>
#include <string.h>
//HOW MANY PIZZAS
int H, W, TOTAL_ROBOTS;

typedef struct s{
	int x;
	int y;
	int d;
}robotType;

void initArray(int a[], int size){
	int i;
	for(i=0; i<size; i++)
		a[i] = 0;
}

int main(){
	scanf("%d %d",&H, &W);
	while(H!=-1 && W!=-1){
		scanf("%d",&TOTAL_ROBOTS);
		int CountArray[H+1];
		//memset(CountArray, 0, TOTAL_ROBOTS+1);
		initArray(CountArray, H+1);
		robotType robot[TOTAL_ROBOTS];
		int i;
		int MAX_COUNT = 0;
		for(i=0; i<TOTAL_ROBOTS; i++){
			scanf("%d %d %d",&robot[i].x, &robot[i].y, &robot[i].d);
		}
		int j;
		for(i=0; i<TOTAL_ROBOTS; i++){
			int Y = robot[i].y;
			int D = robot[i].d;
			for(j=Y-D; j<=Y+D; j++){
				if(j>=0 && j<=H){
					CountArray[j]++;
					if(CountArray[j] > MAX_COUNT)
						MAX_COUNT = CountArray[j];
				}
			}
		}
		printf("%d\n", MAX_COUNT);
		scanf("%d %d",&H, &W);
	}
	return 0;
}