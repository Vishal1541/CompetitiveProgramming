#include <stdio.h>
#include <string.h>
int main(void) {
    int T;
    long long int ctr,ctrzero,ctr1,i;
    scanf("%d",&T);
    while(T--)
    {
        ctr=0;
        ctrzero=0;ctr1=0;
        char a[100000];
        scanf("%s",a); 
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='1')
            {
                ctr1++;
                i++;
                while(a[i]=='0')
                {
                    ctrzero++;
                    i++;
                }
                if(ctrzero>0)
                    ctr=ctr+(ctrzero+1)*ctr1;
                i--;
                ctrzero=0;
            }
        }
        printf("%lld\n",ctr);
    }
	return 0;
}
 