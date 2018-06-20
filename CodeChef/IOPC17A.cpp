//    VISHAL ANAND
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <stack>
#include <functional>

using namespace std;

#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define us unordered_set
#define um unordered_map
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());

int T, tears;
string str;

bool allSame(int a, int b){
	char ch = str[a];
	bool same = true;
	fl(i,a+1,b+1){
		if(str[i]!=ch){
			same = false;
			break;
		}
	}
	return same;
}
int countTears(int a, int b, int t){
	int l = b-a+1;
	if(l==1)	return t;
	char ch = str[a];
	bool same = allSame(a,b);
	if(same)	return t;
	t++;
	if(l%2)		return -1;
	int part1 = countTears(a,(a+b)/2,t);
	int part2 =	countTears((a+b)/2+1,b,t);
	if(part1==part2==-1)
		return -1;
	if(part1!=-1 && part2!=-1)
		return min(part1,part2);
	return max(part1,part2);
}


int main(){
	cin>>T;
	while(T--){
		cin>>str;
		int len = str.length();
		if(allSame(0,len-1)){
			cout<<"0\n";
			continue;
		}
		if(len%2){
			cout<<"-1\n";
			continue;
		}
		tears = 0;
		tears = countTears(0,len-1,tears);
		cout<<tears<<endl;
	}

	return 0;
}