//    VISHAL ANAND
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

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	vi color(30),filled(7,0), opposite(7);
	int total_filled = 0;
	fl(i,1,25)	cin>>color[i];
	if(color[1]==color[2] && color[3]==color[4] && color[1]==color[3])	{filled[1] = 1;total_filled++;}
	if(color[5]==color[6] && color[7]==color[8] && color[5]==color[7])	{filled[2] = 1;total_filled++;}
	if(color[9]==color[10] && color[11]==color[12] && color[9]==color[11])	{filled[3] = 1;total_filled++;}
	if(color[13]==color[14] && color[15]==color[16] && color[13]==color[15])	{filled[4] = 1;total_filled++;}
	if(color[17]==color[18] && color[19]==color[20] && color[17]==color[19])	{filled[5] = 1;total_filled++;}
	if(color[21]==color[22] && color[23]==color[24] && color[21]==color[23])	{filled[6] = 1;total_filled++;}

	opposite[1] = 3;
	opposite[2] = 6;
	opposite[3] = 1;
	opposite[4] = 5;
	opposite[5] = 4;
	opposite[6] = 2;


	if(total_filled!=2){cout<<"NO\n";return 0;}
	if(filled[1] != filled[opposite[1]] ||
		filled[2] != filled[opposite[2]] ||
		filled[3] != filled[opposite[3]]){
		cout<<"NO\n";return 0;
	}
	bool yes = false;
	if(filled[4]==filled[opposite[4]] && filled[4]==1){
		if(color[1]==color[3] && color[6]==color[8] && color[1]==color[6] &&
			color[2]==color[4] && color[22]==color[24] && color[2]==color[22] &&
			color[5]==color[7] && color[10]==color[12] && color[5]==color[10] &&
			color[9]==color[11] && color[21]==color[23] && color[9]==color[21]){
			yes = true;
		}
		else if(color[1]==color[3] && color[21]==color[23] && color[1]==color[23] &&
			color[22]==color[24] && color[10]==color[12] && color[22]==color[10] &&
			color[5]==color[7] && color[2]==color[4] && color[5]==color[2] &&
			color[9]==color[11] && color[6]==color[8] && color[9]==color[6]){
			yes = true;
		}
	}
	else if(filled[1]==filled[opposite[1]] && filled[1]==1){
		if(color[5]==color[6] && color[19]==color[20] && color[5]==color[19] &&
			color[17]==color[18] && color[23]==color[24] && color[17]==color[23] &&
			color[21]==color[22] && color[15]==color[16] && color[21]==color[15] &&
			color[13]==color[14] && color[7]==color[8] && color[13]==color[7]){
			yes = true;
		}
		else if(color[5]==color[6] && color[15]==color[16] && color[5]==color[15] &&
			color[17]==color[18] && color[7]==color[8] && color[17]==color[7] &&
			color[21]==color[22] && color[19]==color[20] && color[21]==color[19] &&
			color[13]==color[14] && color[23]==color[24] && color[13]==color[23]){
			yes = true;
		}
	}
	else if(filled[2]==filled[opposite[2]] && filled[2]==1){
		if(color[3]==color[4] && color[18]==color[20] && color[3]==color[18] &&
			color[17]==color[19] && color[11]==color[12] && color[17]==color[11] &&
			color[9]==color[10] && color[13]==color[15] && color[9]==color[13] &&
			color[14]==color[16] && color[1]==color[2] && color[14]==color[1]){
			yes = true;
		}
		else if(color[3]==color[4] && color[13]==color[15] && color[3]==color[13] &&
			color[17]==color[19] && color[1]==color[2] && color[17]==color[1] &&
			color[9]==color[10] && color[18]==color[20] && color[9]==color[18] &&
			color[14]==color[16] && color[11]==color[12] && color[14]==color[11]){
			yes = true;
		}
	}

	cout<<(yes?"YES\n":"NO\n");

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}