#include <bits/stdc++.h>
#define fl(i,x,y) for(int i=x; i<y; i++)
using namespace std;

int main(){
	int n,s,k;
	cin>>n>>s>>k;
	vector<int> arr(n);
	fl(i,0,n)   cin>>arr[i];
    sort(arr.begin(), arr.end());
    int got = 0;
    fl(i,0,n){
        if(got==s){
            cout<<"YES";
            return 0;
        }
        if(arr[i]>k){
            cout<<"NO";
            return 0;
        }
        k -= arr[i];
        got++;
    }
    cout<<"NO";
}