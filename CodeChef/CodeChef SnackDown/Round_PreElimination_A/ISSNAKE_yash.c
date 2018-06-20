    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int i,j,k;
     
    typedef struct queue
    {
    	int row;
    	int col;
    	struct queue *next;
    }queue;
     
    queue *q;
    int visited[1000][1000];
    int test,n;
    char arr[2][1000];
    int x=0,count=0;
    int ind1=0,ind2=0;
    int c=0;
    	
    queue *push(queue *p , int r,int c)
    {
    	queue *head=p;
    	
    	queue *temp=malloc(sizeof(queue));
    	temp->row=r;
    	temp->col=c;
    	temp->next=NULL;
    	
    	while(p->next!=NULL) p=p->next;
    	p->next=temp;
    	
    	return head;
    }
     
    void find(int index1,int index2)
    {
    	c++;
    		
    	if(index1==0)
    	{
    		if((arr[0][index2+1]=='#' && visited[0][index2+1]==0) && (arr[1][index2]=='#' && visited[1][index2]==0))
    		{
    			visited[1][index2]=1;
    			q=push(q,1,index2);	
    		}
    	
    		else
    		{
    			if(arr[0][index2+1]=='#' && visited[0][index2+1]==0)
    			{
    				visited[0][index2+1]=1;
    				q=push(q,0,index2+1);
    			}
    	
    			if(arr[1][index2]=='#' && visited[1][index2]==0)
    			{
    				 visited[1][index2]=1;
    				 q=push(q,1,index2);
    			}	
    		}
    	}
    	
    	if(index1==1)
    	{
    		
    		if((arr[1][index2+1]=='#' && visited[1][index2+1]==0) && (arr[0][index2]=='#' && visited[0][index2]==0 ))	
    		{
    			visited[0][index2]=1;
    			q=push(q,0,index2);
    		}
    		
    		else
    		{
    			if(arr[1][index2+1]=='#' && visited[1][index2+1]==0)
    			{
    				 visited[1][index2+1]=1;
    				 q=push(q,1,index2+1);		
    			}
    		
    			if(arr[0][index2]=='#' && visited[0][index2]==0)
    			{
    				 visited[0][index2]=1;
    				 q=push(q,0,index2);		
    			}
    		}
    	}
    	
    	
    	q=q->next;
    	if(q==NULL) return;
    	
    	find(q->row,q->col);
    }
     
    int main()
    {
    	
    	scanf("%d",&test);
    	
    	for(j=0;j<test;j++)
    	{
    		memset(visited,0,sizeof visited);
    		memset(arr,'A',sizeof arr);
    		
    		q=malloc(sizeof(queue));
    		
    		count=0;
    		x=0;
    		ind1=10000;
    		ind2=10000;
    		c=0;
    		
    		
    		scanf("%d",&n);
    				
    		scanf("%s",arr[0]);
    		scanf("%s",arr[1]);		
    	
    		for(i=0;i<n;i++)
    		{
    			if(arr[0][i]=='#')
    			{
    				if(x==0)
    				ind1=i;
    				x++;
    				count++;
    			}
    		}
    	
    		x=0;
    		
    		for(i=0;i<n;i++)
    		{
    			if(arr[1][i]=='#')
    			{
    				if(x==0)
    				ind2=i;
    				x++;
    				count++;
    			}
    		}
    		
    		if(ind1==10000 && ind2==10000)
    		{
    			printf("no\n");
    			continue;
    		}
    		
    		
    		if(ind1<=ind2)
    		{
    			visited[0][ind1]=1;	
     
    			q->row=0;
    			q->col=ind1;
    			q->next=NULL;
     
    			find(0,ind1);
    		}
    		
    		if(ind2<ind1)
    		{
    			visited[1][ind2]=1;
    			
    			q->row=0;
    			q->col=ind2;
    			q->next=NULL;
     
    			find(1,ind2);
    		}
    	
    		if(c==count)
    			printf("yes\n");
    		else
    			printf("no\n");	
    	}
    	
    	return 0;
    } 