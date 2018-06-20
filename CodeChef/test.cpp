#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll unsigned long long
using namespace std;
 
int main(){
  set<int> s;
  set<int> :: iterator itr;
  s.insert(5);
  itr = s.begin();
  for(int i=0; i<5; i++){
    if(itr!=s.end()){
      cout<<*itr<<" ";
      itr++;
    }
    else
      break;
  }
}