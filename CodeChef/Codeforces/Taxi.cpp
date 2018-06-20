#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define fld(i,x,y) for(Int i=x; i>=y; i--)
#define vi vector<Int>
#define si set<Int>
#define si_d set<Int, greater<Int> >

int n;

int main(){
	cin>>n;
	vi arr;
	vi visited(n,0);
	fl(i,0,n){
		int input;
		cin>>input;
		arr.push_back(input);
	}
	if(n==1){
		printf("1\n");
		return 0;
	}
	sort(arr.begin(),arr.end());
	int pointer_back = n-1, pointer_front = 0;
	int val_back, val_front;
	int NO_OF_TAXIS = 0;
	while(1){
		if(pointer_front>pointer_back)
			break;
		val_front = arr[pointer_front];
		val_back = arr[pointer_back];
		if(val_back+val_front>4){
			NO_OF_TAXIS++;
			pointer_back--;
			continue;
		}
		if(val_back+val_front==4){
			NO_OF_TAXIS ++;
			pointer_back--;
			pointer_front++;
			continue;
		}
		if(val_back+val_front<4){
			int pointer_front_temp = pointer_front+1;
			if(pointer_front_temp==pointer_back){
				NO_OF_TAXIS++;
				break;
			}
			int sum = val_front+val_back+arr[pointer_front_temp];
			bool loop_break = false;
			while(sum<4){
				pointer_front_temp++;
				if(pointer_front_temp==pointer_back){
					NO_OF_TAXIS++;
					loop_break = true;
					break;
				}
				sum += arr[pointer_front_temp];
			}
			if(loop_break)
				break;
			if(sum<=4)
				pointer_front = pointer_front_temp+1;
			else
				pointer_front = pointer_front_temp;
			pointer_back--;
			NO_OF_TAXIS++;
		}

	}
	printf("%d\n",NO_OF_TAXIS);

	return 0;
}