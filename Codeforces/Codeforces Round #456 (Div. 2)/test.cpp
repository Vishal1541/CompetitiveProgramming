#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef map<int,int> mpii;
typedef map<string,int> mpsi;
#define pb push_back
#define INF 1000000000
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,k;cin>>n>>k;
	ll x=(ll)(log2(n))+1;
	if(k==1)
	{
		cout<<n<<endl;
	}
	else 
	{
		cout<<((ll)pow(2,x))-1<<endl;
	}
	return 0;
}