#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#define int long long int
	int t,n,x,sum=0,i;
	cin>>t;
	while(t-->0)
	{
		
		cin>>x>>n;
		int sum=(n*(n+1)/2)-x;
		if(sum%2!=0)
			cout<<"impossible\n";
		else{
			vector<int>arr(n+1);
			int suma=0,sumb=0;
			for( i=n;i>=1;--i)
			{
				if(i==x)
					{
						arr[i]=2;
						continue;
					}
			    if(suma<sumb)
			    {
			    	suma+=i;
			    	arr[i]=0;
			    }
			    else{
			    	sumb+=i;
			    	arr[i]=1;
			    }
			}
			/*cout<<"suma= "<<suma<<endl;
			cout<<"sumb= "<<sumb<<endl;*/

			
            if(suma==sumb && suma==(sum/2))
			{for( i=1;i<=n;++i)
						{
							cout<<arr[i];
						}
						cout<<endl;
			}
		    else 
		    	cout<<"impossible\n";
		}
	}
return 0;

}