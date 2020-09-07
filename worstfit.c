#include<stdio.h>
int memlayout[10];
int worstfit(int m, int r)
{
   int i,flag=0,max,index=0;
   max=memlayout[0];
   for(i=1;i<m;i++)
   {
        if(memlayout[i]>=max)
        {
              max=memlayout[i];
              index=i;
         }
    }
 if(r<=max)
  {
         memlayout[index]=memlayout[index]-r;
         printf("%d is allocated in  %d kb segment\n",r,max);
         flag=1;
   }
 if(flag==0)
           printf("memory is not allocated for this %d request",r);
if(flag==1)
           return 1;
else
          return 0;
}
int main()
{
   int request[10],i,c=0,m,n,check;
   printf("enter no of memory partitions and requests");
   scanf("%d%d",&m,&n);
   printf("read memeory layout ");
   for(i=0;i<m;i++)
        scanf("%d",&memlayout[i]);
   printf("read request");
  for(i=0;i<n;i++)
        scanf("%d",&request[i]);
   for(i=0;i<n;i++)
   {
        check=worstfit(m,request[i]);
        if(check==1)
            c++;
 }
printf("%d are requests are serviced",c); 
}


