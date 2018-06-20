#include <stdio.h>
#include <string.h>

typedef struct s{
	int goals;
}Football;
Football barc, eibar, madr, mala;

void insert(char team_name[30], int team_goal){
	if(strcmp(team_name, "Barcelona") == 0){
		barc.goals = team_goal;
	}
	else if(strcmp(team_name, "Malaga") == 0){
		mala.goals = team_goal;
	}
	else if(strcmp(team_name, "RealMadrid") == 0){
		madr.goals = team_goal;
	}
	else {
		eibar.goals = team_goal;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	int i;
	for(i=0; i<T; i++){
		char team_name[30];
		int team_goal;
		int j;
		for(j=0; j<4; j++){
			scanf("%s",team_name);
			scanf("%d",&team_goal);
			insert(team_name, team_goal);
		}
		if(madr.goals < mala.goals && barc.goals > eibar.goals)
			printf("Barcelona\n");
		else
			printf("RealMadrid\n");
	}
	return 0;
}