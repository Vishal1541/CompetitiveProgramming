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
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int t;
string s;

Int calculatePower(Int base, Int powerRaised)
{
    if (powerRaised != 1)
        return (base*calculatePower(base, powerRaised-1));
    else
        return 1;
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>t;
	while(t--){
		cin>>s;
		vi sumarr(s.length()+9,0),anss;
		Int sumall = 0, finalans;
		string temp,op;
		int last = s.length()-1;
		fl(i,0,s.length())	sumall += s[i]-'0';
		if(s.length()<=10){
			if((s[last]-'0')%2==1){
				if((sumall-(s[last]-'0'))%3==0){
					fl(i,0,last)	cout<<s[i];
					cout<<endl;
				}
				else if((sumall-(s[last]-'0'))%3!=0){
					cout<<"-1\n";
				}
			}
			else{
				for(int i=last; i>=0; i--){
					sumarr[i] = sumarr[i+1]+(s[i]-'0')*pow(10,(last-i));
				}
				Int push;
				for(int i=last; i>=0; i--){
					if((sumall-(s[i]-'0'))%3==0){
						push = (sumarr[0]-sumarr[i])/10+sumarr[i+1];
						if(push%6==0)	anss.pb(push);
					}
				}
				if(anss.size()==0){
					cout<<"-1\n";
					continue;
				}
				sort(anss);
				finalans = anss[anss.size()-1];
				op = to_string(finalans);
				temp = op;
				for(int i=temp.length(); i<s.length()-1; i++){
					op = "0"+op;
				}
				cout<<op<<endl;
			}
		}
		else{
			if((s[last]-'0')%2==1 && (s[last-1]-'0')%2==1){
				cout<<"-1\n";
			}
			else if((s[last]-'0')%2==1 && (s[last-1]-'0')%2==0){
				if((sumall-(s[last]-'0'))%3==0){
					fl(i,0,last)	cout<<s[i];
					cout<<endl;
				}
				else if((sumall-(s[last]-'0'))%3!=0){
					cout<<"-1\n";
				}
			}
			else{
				vector<string> ss;
				for(int i=0; i<s.length()-1; i++){
					if((sumall-(s[i]-'0'))%3==0){
						string aa="";
						for(int j=0; j<s.length(); j++){
							if(i!=j)	aa += s[j];
						}
						ss.pb(aa);
					}
				}
				string aa="";
				if((sumall-(s[last]-'0'))%3==0 && (s[last-1]-'0')%2==0)
					fl(i,0,last)	aa += s[i];
				ss.pb(aa);
				sort(ss);
				if(ss.size()==0){
					cout<<"-1\n";
					continue;
				}
				else{
					string fin = ss[ss.size()-1];
					fl(i,0,last)	cout<<fin[i];
					cout<<endl;
				}
			}
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}