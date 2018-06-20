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

int n;

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

	cin>>n;
	vvi arr(n,vi(6) );
	fl(i,0,n){
		fl(j,0,6)	cin>>arr[i][j];
	}
	int counter = 1;
	bool found;
	fl(i,0,n){
		found = false;
		fl(j,0,6){
			if(arr[i][j]==counter){
				found = true;
				counter++;
			}
		}
		if(found){i=-1;continue;}
	}
	if(counter<10){cout<<(counter-1)<<endl;return 0;}
	if(n>1){
		fl(i,0,n){
			found = false;
			fl(j,0,6){
				if(arr[i][j]==(counter-counter%10)/10){
					fl(k,0,n){
						fl(l,0,6){
							if(i!=k){
								if(arr[k][l]==counter%10){
									found = true;
									counter++;
									break;
								}
							}
							if(found)break;
						}
						if(found)break;
					}
				}
				if(found)break;
			}
			if(found){i=-1;continue;}
		}
		if(counter<100){cout<<(counter-1)<<endl;return 0;}
	}
	if(n==3){
		fl(i,0,n){
			found = false;
			fl(j,0,6){
				if(arr[i][j]==(counter-counter%100)/100){
					fl(k,0,n){
						fl(l,0,6){
							if(i!=k){
								if(arr[k][l]==((counter%100)-(counter%10))/10 ){
									fl(p,0,n){
										if(p!=k && p!=i){
											fl(q,0,6){
												if(arr[p][q]==(counter%10)){
													found = true;
													counter++;
													break;
												}
											}
										}
										if(found)break;
									}
								}
							}
							if(found)break;
						}
						if(found)break;
					}
				}
				if(found)break;
			}
			if(found){i=-1;continue;}
		}
		cout<<(counter-1)<<endl;
	}

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}