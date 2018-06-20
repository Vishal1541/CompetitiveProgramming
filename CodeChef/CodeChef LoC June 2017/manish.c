#include<stdio.h>
#include<stdlib.h>
int partition(long long int a[],long long int l,long long int u)
{
    long long int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(a[i]<v&&i<=u);
        
        do
            j--;
        while(v<a[j]);
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}
void quick_sort(long long int a[],long long int l,long long int u)
{
    long long int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}
 

int main()
{
long long int i=0,j=0,t,n,s,sum=0,min_val,max_val,c=0,d=0,swap,x=0,flag=1;
scanf("%lld",&t);
for(i=0;i<t;i++)
{
scanf("%lld",&n);
scanf("%lld",&s);
long long int array[n];
for(j=0;j<n;j++)
{
scanf("%lld",&array[j]);
}
flag=1;
sum=0;
/*for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
     /* {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }*/
    quick_sort(array,0,n-1);
   //for(j=0;j<n;j++)
//{
//printf("%lldma\n",array[j]);
//}
 if(s<n*array[0])
 {
    printf("-1\n");
    flag=0;
    goto LOOP;
 }
 else if(s>n*array[n-1])
 {
    printf("-1\n");
    flag=0;
    goto LOOP;
 }
 else if(s==n*array[0])
 {
    printf("%lld\n",array[0]);
    flag=0;
    goto LOOP;
 }
 else if(s==n*array[n-1])
 {
    printf("%lld\n",array[n-1]);
    flag=0;
    goto LOOP;
 }
 else
 {
for(x=0;x<n-1;x++)
{
    sum+=array[x];
    if(s==sum+(n-x-1)*array[x+1])
    {
        flag=0;
        printf("%lld\n",array[x+1]);
        goto LOOP;
    }

}
}
if(flag==1)
{
printf("-1\n");
goto LOOP;
}
LOOP:
printf(" ");
}

    return 0;
}