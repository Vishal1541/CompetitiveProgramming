#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int N, K;

int main(){
	cin>>N>>K;
	pair<int, int> p;
	map<int, int> m;
	map<int, int> :: iterator itr;
	int val;
	for(int i=0; i<N; i++){
		cin>>val;
		itr = m.find(val);
		if(itr != m.end()){
			(itr->second)++;
		}
		else{
			m.insert(pair<int,int>(val,1));
		}
	}
	vector<int> distinct_count_array;
	int vector_pointer = 0;
	for(itr=m.begin(); itr!=m.end(); itr++){
		if(vector_pointer == 0){
			distinct_count_array.push_back(itr->second);
			vector_pointer++;
		}
		else{
			distinct_count_array.push_back(distinct_count_array[vector_pointer-1] + itr->second);
			vector_pointer++;
		}
	}
	//PRINT
	/*int x = 0;
	for(itr=m.begin(); itr!=m.end(); itr++){
		printf("%d, %d, %d\n",itr->first, itr->second, distinct_count_array[x++] );
	}
	*/
	if(m.begin() == --itr){
		printf("0\n");
		return 0;
	}
	int sum = 0, itr_point = 0;
	vector_pointer = 0;
	map<int, int> :: iterator BEGIN_PLUS_ONE = m.begin();
	BEGIN_PLUS_ONE++;
	for(itr=BEGIN_PLUS_ONE; itr!=m.end(); itr++){
		itr_point++;
		map<int,int> :: iterator itr2 = --itr;
		itr++;
		vector_pointer = itr_point - 1;
		while(itr->first - itr2->first < K){
			itr2--;
			vector_pointer--;
			if(vector_pointer == -1)
				break;
		}
		if(vector_pointer == -1)
			continue;
		sum += distinct_count_array[vector_pointer]*itr->second;
	}
	printf("%d\n",sum);

	return 0;
}