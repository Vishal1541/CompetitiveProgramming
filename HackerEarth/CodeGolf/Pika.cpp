#include<iostream>
#define F(i,x,y) for(int i=x;i<y;i++)
#define B l-i-1
#define O cout
using namespace std;int n,l,b=1,f=0;string s;main(){cin>>n>>s;l=s.length();if(l==1){O<<s;return 0;}if(n==1){O<<s<<endl;F(i,1,l-1){O<<s[i];F(j,0,l-2)O<<" ";O<<s[B]<<"\n";}F(i,0,l)O<<s[B];}else{F(i,1,l+1){F(j,0,l-i)O<<" ";O<<s[B+1];if(i>1){F(k,0,b)O<<" ";O<<s[B+1];b+=2;}O<<endl;}b-=4;F(i,1,l){F(j,0,i)O<<" ";O<<s[i];if(i<l-1){F(k,0,b)O<<" ";O<<s[i];b-=2;}O<<endl;}}}