    #include <bits/stdc++.h>
    #define mod 1000000007
    using namespace std;
     
    int main()
    {
    	long long int t,n,m,i,j,a,l,r;
    	cin>>t;
    	while (t--)
    	{
    		cin>>n>>m;
    		long long int arr[m][3];
    		long long int fre[m];
    		long long int res[n];
    		memset(res,0,sizeof(res));
    		for (i=0;i<m;i++)
    		{
    			cin>>a>>l>>r;
    			l--;r--;
    			arr[i][0]=a;
    			arr[i][1]=l;
    			arr[i][2]=r;
    			fre[i]=1;
    		}
    		for (i=m-1;i>=0;i--)
    		{
    			if (arr[i][0]==2)
    			{
    				for (j=arr[i][1];j<=arr[i][2];j++)
    					fre[j]=(fre[j]%mod+fre[i]%mod)%mod;
    				fre[i]=0;
    			}
    		}
    		for (i=0;i<m;i++)
    		{
    			if (fre[i])
    			{
    				res[arr[i][1]]=(res[arr[i][1]]%mod+fre[i]%mod)%mod;
    				res[arr[i][2]+1]=(res[arr[i][2]+1]%mod-fre[i]%mod)%mod;
    			}
    		}
    		for (i=1;i<n;i++)
    		{
    			res[i]=(res[i]%mod+res[i-1]%mod)%mod;
    		}
    		for (i=0;i<n;i++)
    			cout<<res[i]<<" ";
    		cout<<endl;
    	}
    	return 0;
    }