#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int t,n;

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		ll ans = 0;
		ll cnt[3000];
		for(int i=0; i<2007; i++)	cnt[i] = 0;
		for(int i=0; i<n; i++){
			int in;
			cin>>in;
			in += 1000;
			cnt[in]++;
		}
		for(int i=0; i<=2000; i++){
			for(int j=i; j<=2000; j++){
				if(i==j && cnt[i]){
					ans += (cnt[i]*(cnt[i]-1))/2;
				}
				else if(cnt[i] && cnt[j] && ((i+j)&1)==0
						&& cnt[(i+j)/2]){
					ans += cnt[i]*cnt[j];
				}
			}
		}
		cout<<ans<<endl;

	}
	#ifndef LOCAL_DEFINE
        cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
    #endif

	return 0;
}