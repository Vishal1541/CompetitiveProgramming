//VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int a,b,c,zeros = 0,Div,rem,pos = 1,cnt = 0;
mii m,r;
bool inside;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>a>>b>>c;
	// a *= 10;
	// while(a<b){
	// 	a *= 10;
	// 	if(zeros==0)	{m[0] = 1;cnt++;}
	// 	zeros++;
	// 	pos++;
	// }
	// Div = a/b;
	// rem = a%b;
	// rem *= 10;
	// r[rem]++;
	// // if(Div==0)	{m[Div] = 1;zeros++;}
	// // else 	m[Div] = pos;
	// // pos++;
	// if(m[Div]==0){
	// 		m[Div] = pos;
	// 		cnt++;
	// 	}	
	// 	pos++;
	// while(cnt!=10){
	// 	if(rem==0){
	// 		if(zeros==0)	m[0] = pos;
	// 		break;
	// 	}
	// 	inside = false;
	// 	while(rem<b && rem!=0){
	// 		rem *= 10;
	// 		zeros++;
	// 			pos++;
	// 		if(zeros==1){
	// 			m[0] = pos;
	// 			cnt++;
	// 		}
	// 		inside = true;
	// 	}
	// 	if(inside)	continue;
	// 	Div = rem/b;
	// 	rem = rem%b;
	// 	rem *= 10;
	// 	if(r[rem])	break;
	// 	if(m[Div]==0){
	// 		m[Div] = pos;
	// 		cnt++;
	// 	}	
	// 	pos++;
	// }
	// if(m[c])	cout<<m[c];
	// else 	cout<<-1;

//---------------

	a = a*10;
	while(a<b){
		a *= 10;
		if(zeros==0)	{m[0] = 1;cnt++;}
		zeros++;
		pos++;
	}
	Div = a/b;
	rem = a%b;
	rem *= 10;
	r[rem]++;
	m[Div] = pos++;
	cnt++;
	while(cnt<10){
		if(rem==0){
			if(zeros==0)	m[0] = pos;
			break;
		}
		inside = false;
		while(rem<b){
			rem *= 10;
			if(zeros==0)	{m[0] = pos;cnt++;}
			zeros++;
			pos++;
			inside = true;
		}
		if(inside)	continue;
		Div = rem/b;
		rem = rem%b;
		rem *= 10;
		if(m[Div]==0){
			m[Div] = pos;
			cnt++;
		}
		if(r[rem])	break;
		pos++;
	}
	if(c==0 && m[c]==0 && r[rem]==0)	cout<<pos;
	else if(m[c])	cout<<m[c];
	else 	cout<<-1;


	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}
