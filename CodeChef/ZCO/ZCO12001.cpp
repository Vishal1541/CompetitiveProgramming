#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

int N;
int depth=-1, depth_index = 0, max_seq=-1, max_seq_index = 0;
int depth_TEMP=0, depth_index_TEMP = 0, max_seq_TEMP=0, max_seq_index_TEMP = 0;

int main(){
	cin>>N;
	stack<int> s;
	int input;
	for(int i=0; i<N; i++){
		cin>>input;
		if(input==1){
			s.push(input);
			depth_TEMP = s.size();
			if(depth_TEMP==1){
				max_seq_index_TEMP = i;
				max_seq_TEMP = 1;
			}
			else{
				max_seq_TEMP++;
			}
			depth_index_TEMP = i;
			if(depth_TEMP > depth){
				depth = depth_TEMP;
				depth_index = depth_index_TEMP;
			}
		}
		else{
			s.pop();
			max_seq_TEMP++;
		}
		if(max_seq_TEMP>max_seq){
			max_seq = max_seq_TEMP;
			max_seq_index = max_seq_index_TEMP;
		}
	}
	printf("%d %d %d %d\n",depth,depth_index+1,max_seq,max_seq_index+1);

	return 0;
}