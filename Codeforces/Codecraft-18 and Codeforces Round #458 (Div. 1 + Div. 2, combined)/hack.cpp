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
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int mx=*max_element(a.begin(),a.end());
    sort(a.begin(),a.end());
    int cnt=0;
    for(int i=0;i<n;i++)
        if(a[i]==mx)
            cnt++;
    if(cnt==1) {cout<<"Conan\n";return 0;}
    if(cnt%2)
        {cout<<"Conan\n";return 0;}
    else {
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]==a[i]) cnt++;
            else{
                cnt++;
                if(cnt%2) {cout<<"Conan\n";return 0;}
                cnt=0;
            }
        }
    }
    cout<<"Agasa\n";
    return 0;
}