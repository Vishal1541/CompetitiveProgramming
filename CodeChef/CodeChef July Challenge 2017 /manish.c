#include <stdio.h>
int main()
{
	long long int i=0,t,n,b,s1=0,s2=0,l1,j=0;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		s1=0;
		s2=0;
		scanf("%lld",&n);
		scanf("%lld",&b);
		l1=n/(b+1);
		s1=n-l1*b;
		n=l1*b;
		//printf("%lldhi",n);
		for(j=b;j<=n;j+=b)
		{
			//printf("hiii\n");
			s2+=s1;

		}
		printf("%lld\n",s2);
	}
	return 0;
}