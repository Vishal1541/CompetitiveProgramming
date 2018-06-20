#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T;
string dish1[4], dish2[4];

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=0; i<4; i++){
			cin>>dish1[i];
		}
		vector<int> flag(4,0);
		int count = 0;
		for(int i=0; i<4; i++){
			cin>>dish2[i];
			for(int j=0; j<4; j++){
				if(flag[j] == 0){
					if(dish1[j].compare(dish2[i])==0){
						flag[j] = 1;
						count++;
					}
				}
			}
		}
		if(count>=2)
			printf("similar\n");
		else 
			printf("dissimilar\n");
	}

	return 0;
}