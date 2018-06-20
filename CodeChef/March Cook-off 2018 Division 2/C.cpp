#include <bits/stdc++.h>
#define ld long double
#define ll long long int
using namespace std;

ll min(ll a, ll b){return (a<b?a:b);}

int t,n,m,arr[109][109];

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		ld X,n;
		cin>>X;
		n = (-1+sqrt(1+8*X))/2;
		ll n1 = floor(n);
		ll n2 = ceil(n);
		ll p1 = (n1*(n1+1))/2;
		ll p2 = (n2*(n2+1))/2;
		ll ans = min(n1+X-p1, n2+p2-X);
		cout<<ans<<endl;
	}

	return 0;
}