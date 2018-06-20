#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

int N, K;

int main(){
	cin>>N>>K;
	multiset<int> arr;
	for(int i=0; i<N; i++){
		int input;
		cin>>input;
		arr.insert(input);
	}
	if(*arr.begin()>=K){
		printf("0\n");
		return 0;
	}
	multiset<int> :: iterator it1, it2;
	unsigned long long int count = 0;
	for(it1=arr.begin(); it1!=arr.end(); it1++){
		it2 = ++it1;
		it1--;
		if(it2 == arr.end() || (*it1 + *it2 >= K) )
			break;
		int sum = *it1 + *it2;
		if(sum<K){
			count++;
			it2++;
			for(multiset<int> :: iterator it_temp = it2; it_temp!=arr.end(); it_temp++){
				sum = *it1 + *it_temp;
				if(sum<K){
					count++;
					continue;
				}
				break;
			}
		}
	}
	printf("%llu\n",count);

	return 0;
}