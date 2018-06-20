#include <bits/stdc++.h>
using namespace std;

int t,n,m,arr[109][109];

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		cin>>n>>m;
		int last;
		for(int i=0; i<n; i++){
			last = 1;
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
				if(arr[i][j]!=-1)	last = arr[i][j];
				else{
					if(i==0){
						arr[i][j] = last;
					}
					else{
						arr[i][j] = max(last,arr[i-1][j]);
					}
				}
			}
		}
		bool yes = 1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m-1; j++){
				if(arr[i][j]>arr[i][j+1]){
					yes = 0;
					break;
				}
			}
			if(!yes){
				break;
			}
		}
		for(int j=0; j<m; j++){
			for(int i=0; i<n-1; i++){
				if(arr[i][j]>arr[i+1][j]){
					yes = 0;
					break;
				}
			}
			if(!yes){
				break;
			}
		}
		if(!yes){
			cout<<-1<<endl;
		}
		else{
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
		}
	}

	return 0;
}