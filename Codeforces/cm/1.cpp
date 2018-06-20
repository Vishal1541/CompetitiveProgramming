#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e9
#define si(x) x.size()
#define MOD 1000000007
#define Q queue
#define PQ priority_queue
#define fr first
#define sc second
#define pb push_back
#define ss stringstream
#define mp make_pair
#define mh make_heap
#define lb lower_bound
#define ub upper_bound
#define nl "\n"
#define space << " " <<
#define FOR( i, L, U ) for(ll i=L ; i<U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define all(x) x.begin(), x.end()
#define Max(a, b, c) max(a, max(b,c))
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef map<int, int> mii;
typedef map<string, int> msi;
// typedef unordered_map<string, int> umsi;
// typedef unordered_map<int, string> umis;
typedef map<int, string> mis;
typedef map<int , vector<int> > mvi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<vll> vvll;
typedef set<ii> sii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<string> vstr;

int sum = 0, bottles = 0, temp_sum = 0, temp_soda = 0, Time = 999999;

struct cmp{
    bool operator()(const ii& a, const ii& b){
        if(a.sc > b.sc) return 1;
        else if(a.sc == b.sc) return a.fr > b.fr;
        else return 0;
    }    
};
int main(){
    // ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vii ab(n);
    vi arr(n,0);
    FOR(i,0,n) {
        cin >> ab[i].fr;
        sum += ab[i].fr;
    }
    FOR(i,0,n) cin >> ab[i].sc;
    sort(all(ab), cmp());
    while(temp_sum<sum){
        temp_sum += ab[bottles].sc;
        bottles++;
    }
    FOR(i,0,bottles){
        arr[i] = 1;
        temp_soda += ab[i].fr;
    }
    Time = sum - temp_soda;
    int l,temp_vol;
    temp_vol = temp_sum;
    while(1){
        for(int i=n-1; i>=0; i--){
            if(arr[i]==1){
                l = i;
                break;
            }
        }
        FOR(i,l+1,n){
            temp_vol += ab[i].sc - ab[i-1].sc;
            if(temp_vol<sum){
                l = i-1;
                temp_vol = temp_vol - ab[i].sc + ab[i-1].sc;
                break;
            }
            arr[i-1] = 0;
            arr[i] = 1;
            temp_soda += ab[i].fr - ab[i-1].fr;
            Time = min(Time,sum - temp_soda);
            if(i==n-1)  l = n-1;
        }
        int count = 0;
        while(arr[l]){
            count++;
            temp_soda -= ab[l].fr;
            temp_vol -= ab[l].sc;
            arr[l] = 0;
            l--;
        }
        if(count==bottles){
            Time = min(Time, sum - temp_soda);
            break;
        }
        for(int i=l; i>=0; i--){
            if(arr[i]){
                l = i;
                break;
            }
        }
        arr[l] = 0;
        arr[l+1] = 1;
        temp_soda += ab[l+1].fr - ab[l].fr;
        temp_vol += ab[l+1].sc - ab[l].sc;
        l++;
        FOR(i,0,count){
            l++;
            arr[l] = 1;
            temp_soda += ab[l].fr;
            temp_vol += ab[l].sc;
        }
        Time = min(Time, sum - temp_soda);
        int breaker_count = 0;
        for(int i=l; i>=0; i--){
            if(arr[i])  breaker_count++;
            else break;
        }
        if(breaker_count==bottles)
            break;
    }
    cout<<bottles<<" "<<Time<<endl;

    return 0;

}