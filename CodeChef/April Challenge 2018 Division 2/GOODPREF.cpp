#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int t,n;
ll N;
string s;

ll max(ll a, ll b){
	return (a>b?a:b);
}

ll min(ll a, ll b){
	return (a<b?a:b);
}

int main(){
	cin>>t;
	while(t--){
		cin>>s>>N;
		n = s.length();
		ll A,B,as[n], bs[n];
		as[0] = (s[0]=='a'?1:0);
		bs[0] = (s[0]=='b'?1:0);
		for(int i=1; i<n; i++){
			as[i] =  as[i-1] + (s[i]=='a'?1:0);
			bs[i] = bs[i-1] + (s[i]=='b'?1:0);
		}
		A = as[n-1], B = bs[n-1];
		ll ans = 0;
		if(A==B){
			for(int i=0; i<n; i++){
				if(as[i]>bs[i])	ans++;
			}
			ans *= N;
		}
		else if(A>B){
			for(int i=0; i<n; i++){
				ll low = floor((double)(bs[i]-as[i])/(A-B));
				low++;
				low = max(low,0);
				ans += (N-low>0?N-low:0);
			}
		}
		else{
			for(int i=0; i<n; i++){
				ll high = ceil(((double)(as[i]-bs[i]))/(B-A));
				high = min(high,N);
				ans += (high>0?high:0);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}