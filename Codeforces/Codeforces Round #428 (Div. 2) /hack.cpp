#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll arr[1005];
    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    ll gain = 0, sum = 0, total = 0, comp = 0, ans = -1;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        comp = min(sum, 8LL);
        k = k-comp;
        if(sum > 8) {
            //gain = sum - 8;
            sum -= 8;
        }
        else sum = 0;
        if(k <= 0) {
            ans = i+1;
            break;
        }
    }
    if(k > 0) printf("%d\n", -1);
    else printf("%lld\n", ans);
    //printf("%d", ceil(6.8));
}