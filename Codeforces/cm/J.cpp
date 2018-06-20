//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
#define MOD 1000000007
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int sum = 0, bottles = 0, temp_sum = 0, temp_soda = 0, Time = 999999;

struct cmp{
    bool operator()(const pair<Int,Int> & a, const pair<Int,Int> & b){
        if(a.S > b.S) return 1;
        else if(a.S == b.S) return a.F > b.F;
        else return 0;
    }    
};

Int min(Int a, Int b){
    if(a<b) return a;
    return b;
}
int main(){
    ios;
    int n;
    cin >> n;
    vector< pair<Int,Int> > ab(n);
    vi arr(n,0);
    fl(i,0,n) {
        cin >> ab[i].F;
        sum += ab[i].F;
    }
    fl(i,0,n) cin >> ab[i].S;
    sort(ab.begin(),ab.end(), cmp());
    while(temp_sum<sum){
        temp_sum += ab[bottles].S;
        bottles++;
    }
    fl(i,0,bottles){
        arr[i] = 1;
        temp_soda += ab[i].F;
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
        fl(i,l+1,n){
            temp_vol += ab[i].S - ab[i-1].S;
            if(temp_vol<sum){
                l = i-1;
                temp_vol = temp_vol - ab[i].S + ab[i-1].S;
                break;
            }
            arr[i-1] = 0;
            arr[i] = 1;
            temp_soda += ab[i].F - ab[i-1].F;
            Time = min(Time,sum - temp_soda);
            if(i==n-1)  l = n-1;
        }
        int count = 0;
        while(arr[l]){
            count++;
            temp_soda -= ab[l].F;
            temp_vol -= ab[l].S;
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
        temp_soda += ab[l+1].F - ab[l].F;
        temp_vol += ab[l+1].S - ab[l].S;
        l++;
        fl(i,0,count){
            l++;
            arr[l] = 1;
            temp_soda += ab[l].F;
            temp_vol += ab[l].S;
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

}