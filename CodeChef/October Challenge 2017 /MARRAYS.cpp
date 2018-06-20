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
    // #define sort(v) sort(v.begin(),v.end());
    #define F first
    #define S second
    #define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
     
    template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
    template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}
     
    struct store{
    	int *arr, *dp, size;
    	vi min_index, max_index;
    };
     
    int t,n,m;
     
    int main(){
    	ios;
    	cout.precision(10);
    	cout<<fixed;
    	cin>>t;
    	while(t--){
    		cin>>n;
    		store type[n];
    		fl(i,0,n){
    			cin>>m;
    			type[i].arr = new int[m];
    			type[i].dp = new int[m];
    			// memset(type[i].dp, -1, m);
    			int minn = 999999, maxx = -1;
    			fl(j,0,m){
    				cin>>type[i].arr[j];
    				if(type[i].arr[j]<minn){
    					minn = type[i].arr[j];
    				}
    				if(type[i].arr[j]>maxx){
    					maxx = type[i].arr[j];
    				}
    			}
    			fl(j,0,m){
    				if(type[i].arr[j]==minn){
    					type[i].min_index.pb(j);
    				}
    				if(type[i].arr[j]==maxx){
    					type[i].max_index.pb(j);
    				}
    			}
    			type[i].size = m;
    			fl(j,0,m)	type[i].dp[j] = -1;
    		}
    		fl(i,0,type[0].size)	type[0].dp[i] = 0;
    		fl(i,1,n){
    			fl(j,0,type[i-1].size){
    				fl(k,0,type[i].min_index.size())
	    				if(abs(type[i-1].arr[j]-type[i].arr[type[i].min_index[k]])*i + type[i-1].dp[(j+1)%type[i-1].size]>type[i].dp[type[i].min_index[k]]){
	    					type[i].dp[type[i].min_index[k]] = abs(type[i-1].arr[j]-type[i].arr[type[i].min_index[k]])*i + type[i-1].dp[(j+1)%type[i-1].size];
	    				}
    				fl(k,0,type[i].max_index.size())
	    				if(abs(type[i-1].arr[j]-type[i].arr[type[i].max_index[k]])*i + type[i-1].dp[(j+1)%type[i-1].size]>type[i].dp[type[i].max_index[k]]){
	    					type[i].dp[type[i].max_index[k]] = abs(type[i-1].arr[j]-type[i].arr[type[i].max_index[k]])*i + type[i-1].dp[(j+1)%type[i-1].size];
	    				}
    			}
    			fl(j,0,type[i].size){
    				fl(k,0,type[i-1].min_index.size())
	    				if(abs(type[i].arr[j]-type[i-1].arr[type[i-1].min_index[k]])*i + type[i-1].dp[(type[i-1].min_index[k]+1)%type[i-1].size]>type[i].dp[j]){
	    					type[i].dp[j] = abs(type[i].arr[j]-type[i-1].arr[type[i-1].min_index[k]])*i + type[i-1].dp[(type[i-1].min_index[k]+1)%type[i-1].size];
	    				}
    				fl(k,0,type[i-1].max_index.size())
	    				if(abs(type[i].arr[j]-type[i-1].arr[type[i-1].max_index[k]])*i + type[i-1].dp[(type[i-1].max_index[k]+1)%type[i-1].size]>type[i].dp[j]){
	    					type[i].dp[j] = abs(type[i].arr[j]-type[i-1].arr[type[i-1].max_index[k]])*i + type[i-1].dp[(type[i-1].max_index[k]+1)%type[i-1].size];
	    				}
    			}
    		}
    		int ans = -1;
    		fl(i,0,type[n-1].size){
    			if(type[n-1].dp[i]>ans)	ans = type[n-1].dp[i];
    		}
    		cout<<ans<<endl;
    	}
     
     
    	#ifndef LOCAL_DEFINE
    		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
    	#endif
     
    	return 0;
    } 