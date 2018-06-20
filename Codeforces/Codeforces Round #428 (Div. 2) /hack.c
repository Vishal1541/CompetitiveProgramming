#include<stdio.h>

int main()
{
	int n,k;
	static int days,count,arr[100000];
	int i,j,temp;
	
	scanf("%d %d",&n,&k);
	
	for(i=0;i<n;i++) scanf("%d",&arr[i]);

	for(i=0;i<n;i++)
	{
		if(arr[i] > 8)
		{
			temp =  arr[i] - 8;
			arr[i+1] = arr[i+1] + temp;
			count = count + 8; 	
		}
		
		else
		{
			count = count + arr[i];
		}
		
		days++;
		
		if(count >= k) break;
	}
	
	if(count < k) printf("-1");
	else
	printf("%d",days);
	
	return 0;
}