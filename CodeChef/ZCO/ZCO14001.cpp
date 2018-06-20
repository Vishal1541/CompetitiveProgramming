#include <iostream>
#include <cstdio>

using namespace std;

int N, H;
int command[100005], POINTER_TO_COMMAND;
int arr[100005], POINTER_TO_ARRAY;
bool IS_EMPTY = true;
int crane_position=0;

//1=left 2=right 3=pick up 4=drop 0=quit

void moveLeft(){
	if(crane_position!=0)
		crane_position--;
	return;
}

void moveRight(){
	if(crane_position < N-1)
		crane_position++;
	return;
}

void pickUp(){
	if(IS_EMPTY && arr[crane_position]!=0){
		IS_EMPTY = false;
		arr[crane_position]--;
	}
}

void dropDown(){
	if(!IS_EMPTY && arr[crane_position]!=H){
		IS_EMPTY = true;
		arr[crane_position]++;
	}
}

int main(){
	scanf("%d %d",&N,&H);
	POINTER_TO_ARRAY = N-1;
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);
	while(1){
		scanf("%d",&command[POINTER_TO_COMMAND]);
		if(command[POINTER_TO_COMMAND]==0)
			break;
		POINTER_TO_COMMAND++;
	}
	int cmd_no=0;
	bool exit = false;
	for(cmd_no =0; cmd_no<=POINTER_TO_COMMAND; cmd_no++){
		switch(command[cmd_no]){
			case 1: moveLeft(); break;
			case 2: moveRight(); break;
			case 3: pickUp(); break;
			case 4: dropDown(); break;
			default : exit = true; break;
		}
		if(exit)
			break;
	}
	for(int i=0; i<N; i++)
		printf("%d ",arr[i]);

	return 0;
}