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

int N,M;
vi ip(20),out(20);

void fold(vi &arr, vi& folded, int l, int i){
	int idx = 0,b = i;
	if(i+1 <= l-i-1){
		fl(j,i+1,2*i+2)	folded[idx++] = arr[j]+arr[b--];
		fl(j,2*i+2,l)	folded[idx++] = arr[j];
	}
	else{
		fl(j,i+1,l)	folded[idx++] = arr[j] + arr[b--];
		while(b>=0)	folded[idx++] = arr[b--];
	}
}
void foldRev(vi &arr, vi& folded, int l, int i,int idx){
	int b = i;
	if(i+1 <= l-i-1){
		fl(j,i+1,2*i+2)	folded[idx--] = arr[j]+arr[b--];
		fl(j,2*i+2,l)	folded[idx--] = arr[j];
	}
	else{
		fl(j,i+1,l)	folded[idx--] = arr[j] + arr[b--];
		while(b>=0)	folded[idx--] = arr[b--];
	}
}

bool check(vi& folded){
	fl(i,0,M)
		if(folded[i]!=out[i])
			return false;
	return true;
}

bool solve(vi& arr, int l){
	bool chk = false;
	if(l==M){
		chk = true;
		fl(i,0,M){
			if(arr[i]!=out[i]){
				chk = false;
				break;
			}
		}
	}
	if(chk)	return true;
	if(l==M){
		chk = true;
		fl(i,0,M){
			if(arr[i]!=out[M-i-1]){
				chk = false;
				break;
			}
		}
	}
	if(chk)	return true;
	fl(i,0,l-1){
		int len = max(l-i-1,i+1);
		vi folded(len);
		fold(arr,folded,l,i);
		// //
		// fl(k,0,len)	cout<<folded[k]<<" ";
		// cout<<endl;
		// //
		if(len==M){
			chk = check(folded);
			if(chk)	return true;
		}
		else if(len>M){
			chk = solve(folded,l-i-1);
			if(chk)	return true;
		}
	}
	if(chk)	return true;
	
	return false;
}

bool solveRev(vi& arr, int l){
	bool chk = false;
	if(l==M){
		chk = true;
		fl(i,0,M){
			if(arr[i]!=out[i]){
				chk = false;
				break;
			}
		}
	}
	if(chk)	return true;
	if(l==M){
		chk = true;
		fl(i,0,M){
			if(arr[i]!=out[M-i-1]){
				chk = false;
				break;
			}
		}
	}
	if(chk)	return true;
	for(int i=l-1; i>=0; i--){
		int len = max(l-i-1,i+1);
		vi folded(len);
		foldRev(arr,folded,l,i,len-1);
		// //
		// fl(k,0,len)	cout<<folded[k]<<" ";
		// cout<<endl;
		// //
		if(len==M){
			chk = check(folded);
			if(chk)	return true;
		}
		else if(len>M){
			chk = solveRev(folded,l-i-1);
			if(chk)	return true;
		}
	}
	if(chk)	return true;
	
	return false;
}

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>N;
	fl(i,0,N)	cin>>ip[i];
	cin>>M;
	fl(i,0,M)	cin>>out[i];

	bool isPossible = solve(ip,N);
	if(!isPossible)
		isPossible = solveRev(ip,N);
	cout<<(isPossible?"S\n":"N\n");

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}