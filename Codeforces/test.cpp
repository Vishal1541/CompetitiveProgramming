#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        // cout.precision(10);
        double a, b;
        cin >> a >> b;
        double d, x1, x2, ans;
        d = a*a + b*b - a*b;
        x1 = ((1/3.0)*(a+b + sqrt(d)));
        x2 = ((1/3.0)*(a+b - sqrt(d)));
        ans = x1 > x2 ? x2 : x1;
        double r = round(ans);
        cout << fixed << (long long int)(r) << " " << (long long int)(r*(a-r)*(b-r)) << endl;
    }
    return 0;
}