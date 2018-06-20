#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v,a;
int main(){
int n ;
cin>>n;
a.resize(n);
for(int i=0;i<n;i++){
int x , y ;
cin>>x>>y;
v.push_back({y,x});
}
sort(v.begin(),v.end());
a[0].first=a[0].second=-1;
for(int i=0;i<n;i++){
 if (v[i].second>a[0].first)a[0]=v[i];
else{

 if (v[i].second>a[1].first)a[1]=v[i];
else {
cout<<"NO";
return 0;
}
}
}
cout<<"YES";
return 0;
}