    #include <bits/stdc++.h>
    using namespace std;
     
    #define fio ios_base::sync_with_stdio(false),cin.tie(NULL)
    #define ll long long int
    #define ull unsigned long long int
    #define ld long double
    #define vi vector<int> 
    #define ii pair<int,int>
    #define ldld pair<ld,ld>
    #define vii vector<ii>
    #define loop(x,i,a,b) for(x i=a;i<=b;i++)
    #define loopi(i,a,b) for(int i=a;i<=b;i++)
    #define loop2(i,a,b) for(i=a;i<=b;i++)  
    #define rloop(x,i,a,b) for(x i=a;i>=b;i--)
    #define rloopi(i,a,b) for(int i=a;i>=b;i--)
    #define rloop2(i,a,b) for(i=a;i>=b;i--)  
    #define X first
    #define Y second
    //#define fill(a,x) memset(a,x,sizeof(a))
    #define pb push_back
    #define mp make_pair
    #define all(v) v.begin(),v.end()
    const long double PI = atan(1.0)*4.0;
     
    const ll MOD = 1e9+7;
    const ll INF = 1e8;
    const ld EPS = 0.0000001;
    #define N 100010
     
    int main()
    {
    	fio;
    	ll T,n,ans;
    	cin>>T;
    	loopi(tt,0,T-1){
    		cin>>n;
    		ans=0;
    		loopi(b,1,700){
    			if((n-b)<0)
    				continue;
    			ans += sqrt((n-b));
    		}
    		cout<<ans<<endl;
    	}
    	return 0;
    } 