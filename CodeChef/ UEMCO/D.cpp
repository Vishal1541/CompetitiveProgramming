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

pair<int,int> arr[111] = {make_pair(3, 5), make_pair(5, 7), make_pair(11, 13), make_pair(17, 19), make_pair(29, 31), make_pair(41, 43), make_pair(59, 61), make_pair(71, 73), make_pair(101, 103), make_pair(107, 109), make_pair(137, 139), make_pair(149, 151), make_pair(179, 181), make_pair(191, 193), make_pair(197, 199), make_pair(227, 229), make_pair(239, 241), make_pair(269, 271), make_pair(281, 283), make_pair(311, 313), make_pair(347, 349), make_pair(419, 421), make_pair(431, 433), make_pair(461, 463), make_pair(521, 523), make_pair(569, 571), make_pair(599, 601), make_pair(617, 619), make_pair(641, 643), make_pair(659, 661), make_pair(809, 811), make_pair(821, 823), make_pair(827, 829), make_pair(857, 859), make_pair(881, 883), make_pair(1019, 1021), make_pair(1031, 1033), make_pair(1049, 1051), make_pair(1061, 1063), make_pair(1091, 1093), make_pair(1151, 1153), make_pair(1229, 1231), make_pair(1277, 1279), make_pair(1289, 1291), make_pair(1301, 1303), make_pair(1319, 1321), make_pair(1427, 1429), make_pair(1451, 1453), make_pair(1481, 1483), make_pair(1487, 1489), make_pair(1607, 1609), make_pair(1619, 1621), make_pair(1667, 1669), make_pair(1697, 1699), make_pair(1721, 1723), make_pair(1787, 1789), make_pair(1871, 1873), make_pair(1877, 1879), make_pair(1931, 1933), make_pair(1949, 1951), make_pair(1997, 1999), make_pair(2027, 2029), make_pair(2081, 2083), make_pair(2087, 2089), make_pair(2111, 2113), make_pair(2129, 2131), make_pair(2141, 2143), make_pair(2237, 2239), make_pair(2267, 2269), make_pair(2309, 2311), make_pair(2339, 2341), make_pair(2381, 2383), make_pair(2549, 2551), make_pair(2591, 2593), make_pair(2657, 2659), make_pair(2687, 2689), make_pair(2711, 2713), make_pair(2729, 2731), make_pair(2789, 2791), make_pair(2801, 2803), make_pair(2969, 2971), make_pair(2999, 3001), make_pair(3119, 3121), make_pair(3167, 3169), make_pair(3251, 3253), make_pair(3257, 3259), make_pair(3299, 3301), make_pair(3329, 3331), make_pair(3359, 3361), make_pair(3371, 3373), make_pair(3389, 3391), make_pair(3461, 3463), make_pair(3467, 3469), make_pair(3527, 3529), make_pair(3539, 3541), make_pair(3557, 3559), make_pair(3581, 3583), make_pair(3671, 3673), make_pair(3767, 3769), make_pair(3821, 3823), make_pair(3851, 3853), make_pair(3917, 3919), make_pair(3929, 3931), make_pair(4001, 4003), make_pair(4019, 4021), make_pair(4049, 4051), make_pair(4091, 4093), make_pair(4127, 4129), make_pair(4157, 4159), make_pair(4217, 4219), make_pair(4229, 4231)};

int t,n;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>t;
	while(t--){
		cin>>n;
		vector<string> phone(n),ans;
		string sub;
		vector<char> real;
		int k,val;
		fl(i,0,n)	cin>>phone[i];
		cin>>sub;
		cin>>k;
		fl(i,0,sub.length()){
			val = sub[i]-'0'+k;
			string aa = to_string(arr[val-1].S);
			real.pb(aa[0]);
		}

		bool matched = false;
		fl(i,0,n){
			int ptr1 = 0, ptr2 = 0;
			while(ptr1<phone[i].length()){
				int save = ptr1;
				while(phone[i][ptr1]==real[ptr2]){
					ptr1++,ptr2++;
					if(ptr1>=phone[i].length() || ptr2>=real.size())	break;
				}
				if(ptr2>=real.size()){
					ans.pb(phone[i]);
					matched = true;
					break;
				}
				else{
					ptr1 = save+1;
					ptr2 = 0;
				}
			}
		}
		if(!matched)	cout<<"No Numbers Match\n";
		else{
			cout<<ans.size()<<endl;
			fl(i,0,ans.size())	cout<<ans[i]<<endl;
		}
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}