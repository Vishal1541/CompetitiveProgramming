#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

unsigned long long int N;

int main(){
	scanf("%llu",&N);
	multiset<unsigned long long int> s;
	unsigned long long int input;
	for(int i=0; i<N; i++){
		scanf("%llu",&input);
		s.insert(input);
	}
	multiset<unsigned long long int> :: iterator itr;
	unsigned long long int val = 0, revenue = 0;
	int index = -1;
	for(itr = s.begin(); itr!= s.end(); itr++){
		index++;
		if(*itr > val){
			val = *itr;
			if(revenue < val*(N-index)){
				revenue = val * (N-index);
			}
		}
	}
	printf("%llu\n",revenue);

	return 0;
}