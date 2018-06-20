#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, MOD;

long long int findTotalSegments(int a){
	long long int sum = 0;
	for(int i=1; i<=a; i++)
		sum += i;
	return sum;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&N,&MOD);
		vector<int> input_arr(N,0);
		long long int TOTAL_SEGMENTS = findTotalSegments(N);
		vector<int> segments_sum(TOTAL_SEGMENTS,0);
		int pointer = 0;
		for(int i=0; i<N; i++){
			long long int SUM = 0;
			scanf("%d",&input_arr[i]);
			for(int j=i; j>=0; j--){
				SUM = SUM%MOD + input_arr[j]%MOD;
				segments_sum[pointer++] = SUM%MOD;
			}
		}
		sort(segments_sum.begin(), segments_sum.end());
		int MAX = -1, count = 0;
		for(int i=TOTAL_SEGMENTS-1; i>=0; i--){
			if(segments_sum[i] > MAX){
				MAX = segments_sum[i];
				count = 1;
			}
			else if(segments_sum[i] == MAX)
				count++;
			else if(segments_sum[i] < MAX)
				break;
		}
		printf("%d %d\n",MAX,count);
	}

	return 0;
}