#include <iostream>
#include <math.h>

int MOD=1000000007;
using namespace std;


int main()
{
	long long int T;
	cin >> T;

	for (long long int i = 0; i < T; ++i)
	{
		long long int N;
		cin >> N;
		long long int A[N+1];
		long long int sum=0;
		for (long long int k = 0; k < N+1; ++k)
		{
			cin >> A[k];
		}

		
		
		for (long long int j = 1; j < N+1; ++j)
		{
			for (long long int m = 0; m < j; ++m)
			{
			 	if(m!=0)
					sum= sum%MOD + (((int)pow(2,m-1)%(int)MOD)*(A[j])%MOD*(A[m]%MOD))%MOD;
				else
					sum= sum%MOD + ((A[j]%MOD)*(A[m]%MOD))%MOD;
			}
		
			sum=((sum%MOD)*(2%MOD))%MOD;
		}
		
		
		
		sum=sum%MOD;
		cout << sum << endl;
	}
	return 0;
}