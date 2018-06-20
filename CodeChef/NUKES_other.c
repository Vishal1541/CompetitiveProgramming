    #include<stdio.h>
    #define N 30
        
    int fast_readintarray(int[]);
    int main(void)
        {
        int I,val,carry;
        int a[4],n;
    	n=fast_readintarray(a);
    /*printf("\n 0==%d",a[0]);
    printf("\n 1==%d",a[1]);
    printf(" \n2==%d",a[2]);*/
        for(I=0; I<a[2]; I=I+1)
        {
        val = a[0] % (a[1] + 1);
        a[0] = a[0] / (a[1] + 1);
        printf("%d ",val);
        }
        return 0;
    }
     
     
     
    int fast_readintarray(int a[4])
    {
    	int c,i,temp,count=0;
    	char buffer[N];
    	c=read(0,buffer,N);
    	for(i=0;i<c;i++)
    	{
    		if(buffer[i]=='\n')
    		{
    			a[count++]=temp;
    			return count;
    		}
    		
    		else if(buffer[i]==' ')
    		{
    			a[count++]=temp;
    			temp=0;
    		}
    		
    		else
    		{
    			temp=temp*10+buffer[i]-'0';
    		}
    	}
    }  