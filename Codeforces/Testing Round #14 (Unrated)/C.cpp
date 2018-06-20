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
// #define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int nextPowerOf2(Int n)
{
  Int count = 0;
 
  /* First n in the below condition is for the case where n is 0*/
  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}

Int raiseToPow(Int x, Int power)
{
    Int result;
    Int i;
    result =1;
    for (i=1; i<=power;i++)
    {
        result = result*x;
    }
    return(result);
}

Int powerMod(Int x, Int y, Int p)
{
    Int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

struct Type{
  string alnum;
  int len;
};

bool cmp(const Type& a, const Type& b){
  return (a.len > b.len);  
}

bool isChar(char a){
  return (a>='a' && a<='z');
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

  int n;
  cin>>n;
  vector<Type> s(n);
  fl(i,0,n){
    string in;
    cin>>in;
    s[i].alnum = in;
    s[i].len = in.length();
  }
  map<char,int> nonzero;
  fl(i,0,n){
    nonzero[s[i].alnum[0]] = 1;
  }
  sort(s.begin(),s.end(),cmp);
  int M = s[0].len;
  fl(i,0,n){
    fl(j,0,M-s[i].len){
      s[i].alnum = "1"+s[i].alnum;
    }
  }

  // fl(i,0,n){
  //   cout<<s[i].alnum<<endl;
  // }


  vector<int> visited(300,0), alpha(300,-1), num(10,0);
  Int ans = 0;
  fl(j,0,M){
    fl(i,0,n){
      if(isChar(s[i].alnum[j]) && !visited[s[i].alnum[j]]){
        visited[s[i].alnum[j]] = 1;

        if(j==0 || s[i].alnum[j-1]=='1' || nonzero[s[i].alnum[j]]){
          fl(k,1,10){
            if(num[k]==0){
              num[k] = 1;
              alpha[s[i].alnum[j]] = k;
              break;
            }
          }
        }
        else{
          fl(k,0,10){
            if(num[k]==0){
              num[k] = 1;
              alpha[s[i].alnum[j]] = k;
              break;
            }
          }
        }
      }
    }
  }
  // for(char a = 'a'; a<='j'; a++)
  // cout<<"_"<<alpha[a]<<"_";
  fl(i,0,n){
    int temp = 0, mul = 1;
    for(int j=M-1; j>M-1-s[i].len; j--){
      temp = temp + alpha[s[i].alnum[j]]*mul;
      mul *= 10;
    }
    // cout<<temp<<" ";
    ans += temp;
  }
  cout<<ans;

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}
