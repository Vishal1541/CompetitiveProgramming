#define _CRT_SECURE_NO_WARNINGS
#define isws std::ios::sync_with_stdio(false)
#define _USE_MATH_DEFINES
#define ll long long int

#include <bits/stdc++.h>

using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef pair<int, int> PII;
const ll INF = 1000000007;

const int N = 200000 + 7;

map<ll, ll> noc;
int arr[N];

int main()
{

	freopen("ip.txt","r",stdin);
	freopen("op.txt","w",stdout);
	isws;
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i, 0, n) cin >> arr[i];
	ll ans = 0;
	ll tn = 0;
	ll cs = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ans += cs - arr[i] * tn;
		ll o1 = noc[arr[i] + 1];
		ans -= o1;
		o1 = noc[arr[i] - 1];
		ans += o1;
		cs += arr[i];
		tn++;
		noc[arr[i]]++;
	}
	cout << ans << endl;
	return 0;
}