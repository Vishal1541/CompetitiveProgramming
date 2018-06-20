#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>
typedef unsigned long long int llu;

using namespace std;

int main(){
	int N;
	cin>>N;
	set<int> s;
	set<int> :: iterator it, it_back, it_temp, it_end;
	for(int i=0; i<N; i++){
		int input;
		cin>>input;
		s.insert(input);
	}
	int count = 0, MAX=-1, MIN=10000;
	int MAX_INDEX = 0, MIN_INDEX = 0;
	it_back = s.begin();
	for(it=s.begin(); it!=s.end(); it++){
		int val = *it;
		if(val>MAX)
			MAX = val;
		if(val<MIN)
			MIN = val;
		while(MAX-MIN>2){
			it_back++;
			count--;
			MIN = *it_back;
			it_end = ++it;
			it--;
			for(it_temp = it_back; it_temp!=it_end; it_temp++){
				if(*it_temp>MAX)
					MAX = *it_temp;
				if(*it_temp<MIN)
					MIN = *it_temp;
			}
			if(it_back == it)
				break;
		}
		if(MAX-MIN<=2){
			count++;
		}
		if(count==3)
			break;
	}
	if(count==3)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}