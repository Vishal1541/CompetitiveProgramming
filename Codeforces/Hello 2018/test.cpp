#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define X first
#define Y second
#define Maxx 1000007
#define MOD (int)(1e6+3)
#define ninf (int)(-1*(1e6 + 7))
using namespace std;

int nk,m;

    ll powt(ll x, ll n) {
        ll res = 1;
        while (n > 0) {
            if (n&1LL)
                res = res * x;
            if(n != 1)
                x = x * x;
            if(x > m || res > m) {

                return m+1;
            }
            n >>= 1;
            //cout << "n = " << n << "\n";
        }
        return res;
    }

int main() {
    cin >> nk >> m;
    ll ans = powt(2, nk);
    ans = m%ans;
    cout << ans << "\n";
}