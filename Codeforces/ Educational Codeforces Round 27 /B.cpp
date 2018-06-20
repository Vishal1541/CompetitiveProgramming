//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
#define Int long long int
#define fl(i,x,y) for(Int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define us unordered_set
#define um unordered_map
#define mii map<Int,Int>
#define qi queue<Int>
#define pb push_back
#define MOD 1e9+7
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define PI 3.141592653589793238L
#define F first
#define S second
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define mp make_pair
#define _ << " " <<
#define cout cout
#define continue continue
#define break break
#define endl endl
template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

int main(){
	ios;
	string str;
	vi arr1(3),arr2(3);
	int sum1=0,sum2=0,count=0,more,diff;
	cin>>str;
	fl(i,0,3)	arr1[i] = str[i]-'0';
	fl(i,0,3)	arr2[i] = str[i+3]-'0';
	sort(arr1);
	sort(arr2);
	fl(i,0,3){
		sum1 += arr1[i];
		sum2 += arr2[i];
	}
	more = (sum1>sum2)?1:2;
	while(sum1!=sum2){
		if(more==2){
			diff = sum2-sum1;
			diff += arr1[0];
			if(diff>9){
				sum1 = sum1-arr1[0]+9;
				arr1[0] = 9;
			}
			else{
				sum1 = sum1- arr1[0]+diff;
				arr1[0] = diff;
			}
			sort(arr1);
		}
		else{
			diff = sum1-sum2;
			diff += arr2[0];
			if(diff>9){
				sum2 = sum2-arr2[0]+9;
				arr2[0] = 9;
			}
			else{
				sum2 = sum2- arr2[0]+diff;
				arr2[0] = diff;
			}
			sort(arr2);
		}
		count++;
	}

	int count2=0;
	fl(i,0,3)	arr1[i] = str[i]-'0';
	fl(i,0,3)	arr2[i] = str[i+3]-'0';
	sort(arr1);
	sort(arr2);
	fl(i,0,3){
		sum1 += arr1[i];
		sum2 += arr2[i];
	}
	if(sum2>sum1){
		int diff = sum2-sum1;
		diff -= arr2[2];
		count2++;
		if(diff>0){
			diff -= arr2[1];
			count2++;
			if(diff>0){
				diff -= arr2[0];
				count2++;
			}
		}
	}
	else{
		int diff = sum1-sum2;
		diff -= arr1[2];
		count2++;
		if(diff>0){
			diff -= arr1[1];
			count2++;
			if(diff>0){
				diff -= arr1[0];
				count2++;
			}
		}
	}

	cout<<min(count,count2)<<endl;
	
	return 0;
}