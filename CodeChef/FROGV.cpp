#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int N, K, P;

int main(){
	scanf("%d %d %d",&N,&K,&P);
	pair<int,int> p;
	multimap<int,int> m;
	int frogDist, frogNo = 0;
	for(int i=0; i<N; i++){
		scanf("%d",&frogDist);
		p.first = frogDist;
		p.second = ++frogNo;
		m.insert(p);
	}
	multimap<int, int> :: iterator link[N+1];
	for(multimap<int, int> :: iterator itr = m.begin(); itr!= m.end(); itr++){
		frogNo = itr->second;
		link[frogNo] = itr;
	}
	int frog1, frog2;
	multimap<int, int> :: iterator itr_frog1, itr_frog2;
	for(int i=0; i<P; i++){
		scanf("%d %d",&frog1,&frog2);
		itr_frog1 = link[frog1];
		itr_frog2 = link[frog2];
		if(itr_frog1->first == itr_frog2->first){
			printf("Yes\n");
			continue;
		}
		if(itr_frog2->first < itr_frog1->first)
			swap(itr_frog1, itr_frog2);
		bool flag = true;
		//printf("frog1 %d\n",itr_frog1->first);
		//printf("frog2 %d\n",itr_frog2->first);
		
		while(1){

			int dis1 = itr_frog1->first;
			itr_frog1++;
			int dis2 = itr_frog1->first;
			//printf("dist1 %d dist2 %d\n", dis1, dis2);
			if(dis2-dis1 > K){
				flag = false;
				break;
			}
			if(itr_frog1 == itr_frog2)
				break;
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
			
	}

	return 0;
}