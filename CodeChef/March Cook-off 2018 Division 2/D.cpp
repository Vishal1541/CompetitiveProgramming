#include <bits/stdc++.h>
#define ld long double
#define ll long long int
using namespace std;

ll min(ll a, ll b){return (a<b?a:b);}
ll max(ll a, ll b){return (a>b?a:b);}

const int MAX = 1e5+7, MOD = 1e9+7;
ll ans,t,n,m,k,l,r,arr[MAX],Plus[MAX],Minus[MAX],plusArr[MAX],minusArr[MAX];

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		ans = 1;
		vector<pair<ll,ll> > mix, justplus, justminus;
		Plus[0] = Minus[0] = 0;
		for(int i=1; i<=n; i++){
			cin>>arr[i];
			Plus[i] = Minus[i] = plusArr[i] = minusArr[i] = 0;
		}
		while(m--){
			char ch;
			cin>>ch;
			if(ch=='I'){
				cin>>l>>r;
				Plus[r]++,Plus[l]--;
			}
			else{
				cin>>l>>r;
				Minus[r]++,Minus[l]--;
			}
		}
		int P = 0, M = 0;
		for(int i=n; i>=1; i--){
			P += Plus[i];
			M += Minus[i];
			plusArr[i] += P;
			minusArr[i] += M;
		}
		bool yes = 1;
		for(int i=1; i<=n; i++){
			if(plusArr[i] && minusArr[i]){
				yes = 0;
				break;
			}
		}
		if(!yes){
			cout<<0<<endl;
			continue;
		}
		P = M = 0;
		l = r = 0;
		for(int i=n; i>=1; i--){
			if(plusArr[i] || minusArr[i]){
				if(plusArr[i])	P = 1;
				if(minusArr[i])	M = 1;
				if(!r)	r = i;
			}
			else if(plusArr[i]==0 && minusArr[i]==0){
				if(r){
					l = i;
					if(P && M){
						mix.push_back({l,r});
					}
					else if(P){
						justplus.push_back({l,r});
					}
					else{
						justminus.push_back({l,r});
					}
					l = r = P = M = 0;
				}
				else if(arr[i]==-1){
					ans *= k;
					ans = (ans%MOD);
				}
			}
		}
		int positive, negative;
		for(int i=0; i<justplus.size(); i++){
			l = justplus[i].first, r = justplus[i].second;
			M = positive = 0;
			for(int j=r; j>=l; j--){
				if(arr[i]==-1)	M++;
				else{
					if(positive==0){
						positive = arr[i];
						if(arr[i]+M>k){
							yes = 0;
							break;
						}
						M = 0;
					}
					else{
						if(positive-arr[i]-1!=M){
							yes = 0;
							break;
						}
						positive = arr[i];
						M = 0;
					}
				}
			}
			if(!yes)	break;
			if(arr[l]==-1)	M--;
			else 	continue;
			if(positive==0){
				if(1+M>k){
					yes = 0;
					break;
				}
				ans *= (k-M);
				ans = (ans%MOD);
			}
			else{
				if(positive-M-1<1)	yes = 0;
			}
		}
		for(int i=0; i<justminus.size(); i++){
			l = justminus[i].first, r = justminus[i].second;
			M = negative = 0;
			for(int j=r; j>=l; j--){
				if(arr[i]==-1)	M++;
				else{
					if(negative==0){
						negative = arr[i];
						if(arr[i]-M<1){
							yes = 0;
							break;
						}
						M = 0;
					}
					else{
						if(arr[i]-negative-1!=M){
							yes = 0;
							break;
						}
						negative = arr[i];
						M = 0;
					}
				}
			}
			if(!yes)	break;
			if(arr[l]==-1)	M--;
			else 	continue;
			if(negative==0){
				if(1+M>k){
					yes = 0;
					break;
				}
				ans *= (k-M);
				ans = (ans%MOD);
			}
			else{
				if(negative+M+1>k)	yes = 0;
			}
		}
		if(!yes){
			cout<<0<<endl;
			continue;
		}
		for(int i=0; i<mix.size(); i++){
			l = mix[i].first, r = mix[i].second;
			M = negative = 0;
			int idx = -1;
			for(int j=l; j<=r; j++){
				if(arr[j]!=-1){
					negative = arr[i];
					idx = i;
					break;
				}
			}
			if(idx==-1){
				ll mini = 99999999999, maxi = -2, curr = 1;
				for(int j=l+1; j<=r; j++){
					if(plusArr[j])	curr++;
					else 	curr--;
					mini = min(mini,curr);
					maxi = max(maxi,curr);
				}
				if(mini<1)	maxi += 1-mini;
			}
			int curr = arr[idx];
			for(int j=idx-1; j>=l; j--){
				if(plusArr[j])	curr--;
				else 	curr++;
				if(curr<1 || curr>k){
					yes = 0;
					break;
				}
			}
			for(int j=idx+1; j<=r; j++){
				if(plusArr[j])	curr++;
				else	 curr--;
				if(curr<1 || curr>k){
					yes = 0;
					break;
				}
			}
			if(!yes)	break;
		}
	}

	return 0;
}