#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long Int;
using namespace std;

int main()
{ _
    int a,b,x;
    cin >> a >> b >> x;
    string current = "01";
    int ar[]={a,b};
    if(x==1)
    {
        for(int i=0; i<a; ++i) cout << 0;
        for(int j=0; j<b; ++j) cout << 1;
        cout << endl;
        return 0;
    }
    int i, initI;
    if(a>b) 
    {
        i=0, initI=0;
    }
    else
        i=1, initI=1;
    int swaps=0;
    for(i; swaps<x-1; ++i)
    {
        ++swaps;
        ar[i%2]--;
        cout << current[i%2];
    }
    for(int j=0; j<ar[i%2]; j++)
        cout << current[i%2];
    i++;
        
    for(int j=0; j<ar[i%2]; j++)
        cout << current[i%2];
    cout << endl;
    
}