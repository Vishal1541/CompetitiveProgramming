#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int n;

int main(){
	cin>>n;
	vector<int> arr;
	set<int, greater<int> > length_arr;
	int input;
	int MAX=0, MIN=0, MAX_INDEX=0, MIN_INDEX=0;
	int LENGTH = 0, BACK=0;
	for(int i=0; i<n; i++){
		//printf("i=%d min ind %d max ind %d back %d...\n",i-1,MIN_INDEX,MAX_INDEX,BACK);
		cin>>input;
		arr.push_back(input);
		if(i==0){
			MAX = input;
			MIN = input;
			MAX_INDEX = 0;
			MIN_INDEX = 0;
			BACK = 0;
			LENGTH = 1;
			length_arr.insert(LENGTH);
			continue;
		}
		else{
			if(input>MAX){
				MAX = input;
				MAX_INDEX = i;
			}
			if(input<MIN){
				MIN = input;
				MIN_INDEX = i;
			}
			if(MAX-MIN <= 1){
				LENGTH++;
				length_arr.insert(LENGTH);
				//printf("LEN %d\n", LENGTH);
				continue;
			}
			while(1){
				BACK++;
				if(BACK>MIN_INDEX){
					MIN_INDEX = BACK;
					MIN = arr[MIN_INDEX];
					for(int j=BACK; j<=i; j++){
						int num = arr[j];
						if(num<MIN){
							MIN = num;
							MIN_INDEX = j;
						}
					}
				}
				if(BACK>MAX_INDEX){
					MAX_INDEX = BACK;
					MAX = arr[MAX_INDEX];
					for(int j=BACK; j<=i; j++){
						int num = arr[j];
						if(num>MAX){
							MAX = num;
							MAX_INDEX = j;
						}
					}
				}
				if(MAX-MIN<=1)
					break;
			}
			LENGTH = i-BACK+1;
			length_arr.insert(LENGTH);
		}
	}
	printf("%d\n",*length_arr.end());
	

	return 0;
}
