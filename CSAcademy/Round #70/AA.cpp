#include <bits/stdc++.h>

using namespace std;

int hasholes(int a){
    if(a==0 || a==6 || a==9)    return 1;
    if(a==8)    return 2;
    return 0;
}

int main(){
	int a,b;
    cin>>a>>b;
    int ans, maxx = -1;
    for(int i=a; i<=b; i++){
        int holes = 0;
        string temp = to_string(i);
        for(int j=0; j<temp.length(); j++) holes += hasholes(temp[j]-'0');
        if(holes>maxx){
            maxx = holes, ans = i;
        }
    }
    cout<<ans;
}