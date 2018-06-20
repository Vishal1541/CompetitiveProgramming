#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fr(i,x,y) for(int i=x; i<y; i++)

int t,n;
Int val;
Int sum=0,k,temp;
bool flag=false;
int arr[1000000];
Int sumarray[1000000];
int ptr1=0,ptr2;
int pos=0;
Int mx;
Int maxx;

int main()
{
	ios;

	cin >> t;


	while(t--)
	{
		cin >> n >> k;
		pos=0;
		maxx = -2000000;
		sum=0;
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
			sum+= arr[i];
			if(arr[i]>0)
				pos++;
			if(maxx < arr[i])
				maxx = arr[i];
		}
		sum = sum*k;

		if(k!=1)
		{
			n = n*2;
			int x=0;
			for(int i=n/2;i<n;i++)
			{
				arr[i] = arr[x];
				x++;
			}	
		}	
		
		int counter=0;

		if(pos>0)
		{
			temp = 0;
			mx = 0;	
			ptr1=0;

			fr(i,0,n)
			{
				temp+= arr[i];

				if(counter==1)
				{
					ptr1 = i;
					counter=0;
				}

				if(mx < temp)
				{
					mx = temp;
					ptr2 = i;
				}		

				if(temp < 0)
				{
					temp = 0;
					counter=1;
				}						
			}

			if(k!=1) n/=2;
			temp = min(ptr1%n,ptr2%n);
			ptr2 = max(ptr1%n,ptr2%n);
			ptr1 = temp-1;
			ptr2++;
			while(ptr1>=0)
			{
				sum -= arr[ptr1];
				ptr1--;
			}	

			while(ptr2<n)
			{
				sum-= arr[ptr2];
				ptr2++;
			}	

			cout << max(mx,sum) << endl;
		}
		else
			cout << maxx << endl;


	}

	return 0;
}