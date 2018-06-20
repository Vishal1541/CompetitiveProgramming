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
    #define MOD 1000000007
    #define msi_it  multiset<Int> :: iterator
    #define si_it set<Int> :: iterator
    #define sort(v) sort(v.begin(),v.end());
    #define F first
    #define S second
    #define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
     
    template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
    template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}
     
    int t,x,y;
    string s;
     
    int main(){
    	ios;
    	cout.precision(10);
    	cout<<fixed;
     
    	cin>>t;
    	while(t--){
    		int counter[2];
    		counter[0] = counter[1] = 0;
    		cin>>s>>x>>y;
    		fl(i,0,s.length()){
    			if(s[i]=='a')	counter[0]++;
    			else 	counter[1]++;
    		}
    		int x_ = 0, y_ = 0;
    		char prv = 'x';
    		while(!(counter[0]==0 && counter[1]==0)){
    			if(counter[0]>counter[1]){
    				if(x_<x){
    					cout<<"a";
    					prv = 'a';
    					x_++, counter[0]--;
    					y_ = 0;
    				}
    				else if(y_<y && counter[1]>0){
    					cout<<"b";
    					prv = 'b';
    					y_++, counter[1]--;
    					x_ = 0;
    				}
    				else{
    					cout<<"*a";
    					counter[0]--;
    					x_ = 1;
    					y_ = 0;
    				}
    			}
    			else{
    				if(y_<y){
    					cout<<"b";
    					prv = 'b';
    					y_++, counter[1]--;
    					x_ = 0;
    				}
    				else if(x_<x && counter[0]>0){
    					cout<<"a";
    					prv = 'a';
    					x_++, counter[0]--;
    					y_ = 0;
    				}
    				else{
    					cout<<"*b";
    					y_ = 1;
    					x_ = 0;
    					counter[1]--;
    				}
    			}
    		}
    		cout<<endl;
    	}
     
    	#ifndef LOCAL_DEFINE
    		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
    	#endif
     
    	return 0;
    } 