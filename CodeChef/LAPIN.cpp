#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int T;
string str;

int main(){
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		cin>>str;
		int len = str.length();
		pair<char,int> p;
		map<char,int> m1, m2;
		map<char,int> :: iterator itr1, itr2;
		if(len%2){
			for(int j=0; j<len/2; j++){
				p.first = str[j];
				p.second = 0;
				m1.insert(p);

				p.first = str[j+len/2+1];
				p.second = 0;
				m2.insert(p);
			}
			map<char,int> :: iterator itr1, itr2;
			for(int j=0; j<len/2; j++){
				itr1 = m1.find(str[j]);
				itr1->second++;
				itr2 = m2.find(str[j+len/2+1]);
				itr2->second++;
			}
		}
		else{
			for(int j=0; j<len/2; j++){
				p.first = str[j];
				p.second = 0;
				m1.insert(p);

				p.first = str[j+len/2];
				p.second = 0;
				m2.insert(p);
			}
			for(int j=0; j<len/2; j++){
				itr1 = m1.find(str[j]);
				itr1->second++;
				itr2 = m2.find(str[j+len/2]);
				itr2->second++;
			}
		}
		itr1 = m1.begin();
		itr2 = m2.begin();
		bool flag = true;
		while(1){
			if(itr1==m1.end() && itr2==m2.end())
				break;
			if(itr1->first == itr2->first && itr1->second == itr2->second){
				itr1++;
				itr2++;
			}
			else{
				flag = false;
				break;
			}

		}
		if(!flag)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}