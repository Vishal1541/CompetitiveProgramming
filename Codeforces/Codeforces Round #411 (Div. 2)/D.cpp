//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
// #define MOD 1000000007
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int MOD = 1000000007;

Int power(Int x, unsigned Int y, Int p)
{
    Int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = ((res%p)*(x%p)) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = ((x%p)*(x%p)) % p;  
    }
    return res;
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	string s;
	Int acount = 0, bcount = 0, ans = 0;
	bool a;
	cin>>s;
	// fl(i,0,s.length()){
	// 	a = false;
	// 	while(s[i]=='a'){
	// 		a = true;
	// 		acount++;
	// 		i++;
	// 		if(i==s.length())	break;
	// 	}
	// 	if(i==s.length())	break;
	// 	if(a){
	// 		while(s[i]=='b'){
	// 			ans += (power(2,acount,MOD) - 1)%MOD;
	// 			i++;
	// 			if(i==s.length())	break;
	// 		}
	// 		i--;
	// 	}
	// }
	for(int i=s.length()-1; i>=0; i--){
		while(s[i]=='b'){
			bcount++;
			i--;
			if(i<0)	break;
		}
		if(i<0)	break;
		ans = ((ans%MOD) + (bcount%MOD))%MOD;
		bcount = ((bcount%MOD)*2)%MOD;
	}
	cout<<ans;

	return 0;
}