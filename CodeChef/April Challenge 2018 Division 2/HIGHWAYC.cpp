#include <bits/stdc++.h>
#define ld long double

using namespace std;

int t,n;
ld S,Y,margin = 0.000001;

int main(){
	cout.precision(10);
	cout<<fixed;
	cin>>t;
	while(t--){
		cin>>n>>S>>Y;
		ld V[n],D[n],P[n],C[n];
		for(int i=0; i<n; i++)	cin>>V[i];
		for(int i=0; i<n; i++)	cin>>D[i];
		for(int i=0; i<n; i++)	cin>>P[i];
		for(int i=0; i<n; i++)	cin>>C[i];
		ld T = Y/S, tt = 0;
		for(int i=0; i<n; i++){
			ld curr = (D[i]==1?V[i]*(tt)+P[i]:-V[i]*(tt)+P[i]);
			ld next = (D[i]==1?V[i]*(tt+T)+P[i]:-V[i]*(tt+T)+P[i]);
			if(D[i]==1 && next<-margin || D[i]==1 && curr-C[i]>margin
				|| D[i]==0 && next>margin || D[i]==0 && curr+C[i]<-margin){
				tt += T;
			}
			else{
				if(D[i]==1){
					tt += T + (margin + C[i] - curr)/V[i];
				}
				else{
					tt += T + (curr - (-margin-C[i]))/V[i];
				}
			}
		}
		cout<<tt<<endl;
	}

	return 0;
}