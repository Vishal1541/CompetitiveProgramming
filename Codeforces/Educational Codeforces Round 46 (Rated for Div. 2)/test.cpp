#include <cmath>
 #include <cstdio>
 #include <vector>
 #include <string.h>
 #include <iostream>
 #include <algorithm>
 using namespace std;

//comparing function only sorts if string size is equal and keeps the larger integgers at last.
bool myfunction (string i,string j) 
{ 
int n=i.length();
int m=j.length();
if(n==m)
    return (i<j);

return n<m;   
  }


int main() {
int n;
cin>>n;
vector <string> arr(n);
vector <string> arr1(n);
for(int i=0;i<n;i++)
{
    cin>>arr[i];
    
}
for(int i=0;i<n;i++)
{
    cin>>arr1[i];
    
}


sort(arr.begin(),arr.end(),myfunction);
sort(arr1.begin(),arr1.end(),myfunction);

int count=0;
for(int i=0;i<n;i++)
{
    if(strcmp(arr[i].c_str(),arr1[i].c_str())==0)
    count++;
}
cout<<n-count<<endl;

return 0;
 }