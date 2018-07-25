8. #include <stdio.h>
#include<stdlib.h>
#define MAX_QUEUE 10
typedef struct queue
{ int data;
struct queue* link;
}queue;
struct queue* front[MAX_QUEUE];
struct queue* rear[MAX_QUEUE];
void addq(int i, int item)
{
struct queue* temp;
temp=(queue*)malloc(sizeof(*temp));
temp->data=item;
temp->link=NULL;
if(front[i])
rear[i]->link=temp;
else
front[i]=temp;
rear[i]=temp;
}
int deleteq(int i)
{
struct queue* temp;
temp=(queue*)malloc(sizeof(*temp));
int item;
temp=front[i];if(!temp)
{printf("error\n");
return -999;
}
item=temp->data;
front[i]=temp->link;
free(temp);
return item;
}
int main()
{
int i,option,n;
int ret,item;
struct queue* temp;
temp=(queue*)malloc(sizeof(*temp));
for(i=1;i<=MAX_QUEUE;i++)
{front[i]=NULL;
rear[i]=NULL;
}
while(1)
{
printf ("\n enter your option\n 1. addq \n 2. deleteq \n 3. display \n 4. exit\n");
scanf("%d",&option);
switch (option)
{
case 1: printf("enter the data\n");
scanf("%d",&item);
printf("enter the queue number\n");
scanf ("%d",&n);
addq(n,item);
break;
case 2: printf("enter the queue number\n");
scanf("%d",&n);ret=deleteq(n);
printf("deleted item is %d\n",ret);
break;
case 3:printf("enter the queue number that you want to display\n");
scanf("%d",&i);
if(front[i]==NULL)
printf("queue is empty\n");
else
{
for(temp=front[i];temp!=NULL;temp=temp->link)
printf("%d \t",temp->data);
}
break;
case 4:
exit(0);
}}}