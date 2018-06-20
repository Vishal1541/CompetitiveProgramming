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

int N, K;

llu sigma(int a){
	llu sum = a-1;
	for(int i = a-2; i>=1; i--)
		sum += i;
	return sum;
}

int main(){
	cin>>N>>K;
	pair<int,int>p;
	map<int,int>m;
	map<int,int> :: iterator it, it1, it2, it_temp;
	vector<bool> flag(N,false);
	int flag_pointer = 0;

	int input;
	for(int i=0; i<N; i++){
		cin>>input;
		it = m.find(input);
		if(it==m.end()){
			m.insert(pair<int,int>(input,1));
			continue;
		}
		(it->second)++;
	}
	if(m.begin()->first >= K){
		printf("0\n");
		return 0;
	}
	llu count = 0;
	it1 = m.begin();
	if((it1->first)*2 < K && it1->second>1){
		llu summation = sigma(it1->second);
		count += summation;
		flag[flag_pointer] = true;
		flag_pointer++;
	}
	int it1_pointer = 0;
	for(it1=m.begin(); it1!=m.end(); it1++){
		it2 = ++it1;
		flag_pointer = it1_pointer + 1;
		it1--;
		if(it2 == m.end())
			break;
		if((it2->first)*2 < K && it2->second>1 && flag[flag_pointer]==false){
			llu summation = sigma(it2->second);
			count += summation;
			flag[flag_pointer] = true;
		}
		int sum = it1->first + it2->first;
		if(sum<K){
			count += it1->second * it2->second;
			it2++;
			for(it_temp = it2; it_temp!=m.end(); it_temp++){
				flag_pointer++;
				sum = it1->first + it_temp->first;
				if((it_temp->first)*2 < K && it_temp->second>1 && flag[flag_pointer]==false){
					llu summation = sigma(it_temp->second);
					count += summation;
					flag[flag_pointer] = true;
				}
				if(sum<K){
					count += it1->second * it_temp->second;
					continue;
				}
				break;
			}
		}
	}
	printf("%llu\n",count);

	return 0;
}