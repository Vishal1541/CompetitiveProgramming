#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,w,MOD = 1e9+7;

ll powerModulo(ll a, ll b){
    ll ret = 1;
    a = a % MOD;
    while (b > 0){
        if (b & 1)
            ret = (ret*a) % MOD;
        b = b>>1;
        a = (a*a) % MOD;  
    }
    return ret;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>w;
		ll ans = powerModulo(10,n-2);
		if(w>=-9 && w<0){
			ans = ((10+w)*ans)%MOD;
		}
		else if(w>=0 && w<=8){
			ans = ((9-w)*ans)%MOD;
		}
		else{
			ans = 0;
		}
		cout<<ans<<endl;
	}

	return 0;
}