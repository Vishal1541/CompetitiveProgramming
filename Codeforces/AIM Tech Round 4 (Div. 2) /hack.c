#include <stdio.h>
#include <string.h>

int main()
{
	char s[2000],ss[1000];
	int k=0,c=0;
	int i=0,j=0,x=0;
	int visited[30];
	for(int i=0;i<30;i++)   visited[i]=0;
	int count=0;

	scanf("%s",s);
	scanf("%d",&k);

	for(i=0;i<strlen(s);i++)
	{
		if(visited[(int)s[i]-97]==0)
			count++;
		
		else
		{
			ss[j] = s[i];
			j++;
		}

		visited[(int) s[i]-97]++;
	}

	if(count>=k)
	{
		printf("0");
		return 0;
	}

	for(i=0;i<j;i++)
	{
		for(x=0;x<26;x++)
		{
			if(visited[x]==0)
			{
				count++;
				visited[x]++;
				c++;
				break;
			}
		}

		if(count>=k)
			break;
	}


	if(count>=k) printf("%d",c);
	else printf("impossible");

	return 0;
}