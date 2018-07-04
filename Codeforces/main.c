#include <stdio.h>
 
char a[200][200];

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    getchar();
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%c",&a[i][j]);
        }
        getchar();
    }
   
    int k=0;
     for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
           if(a[i][j]=='.')
           {
               a[i][j]='W';
               k=1;
               break;
              
           }
           
        }
        if(k==1){break;}
    }    
            for(int i=1;i<=m;i++)
        {
        for(int j=1;j<=n;j++)
        {
           if(a[i][j]=='.')
           {
               
               if(a[i-1][j]=='W'||a[i+1][j]=='W'||a[i][j+1]=='W'||a[i][j-1]=='W')
               {
                   a[i][j]='B';
               }
               else a[i][j]='W';
           }
        }
       
    }
     for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
