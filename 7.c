7. #include <stdio.h>
#include<stdlib.h>
#define MAX_STACKS 10
typedef struct stack
{ int data;
struct stack* link;
}stack;
struct stack* top[MAX_STACKS];
void push(int i, int item)
{
struct stack* temp;
temp=(stack *)malloc(sizeof(*temp));
temp->data=item;
temp->link=top[i];
top[i]=temp;}
int pop(int i)
{
struct stack* temp;
temp=(stack*)malloc(sizeof(*temp));
temp=top[i];
int item;
if(!top[i])
{printf("error\n");
return -999;
}
item=temp->data;
top[i]=temp->link;
free(temp);
return item;
}
int main()
{
int i,option,n,j;
int ret,item;
struct stack* temp;
temp=(stack*)malloc(sizeof(*temp));
for(i=1;i<=MAX_STACKS;i++)
{top[i]=NULL;}
while(1)
{
printf ("\n enter your option\n1. push\n2. pop\n3. display\n4. exit\n");
scanf("%d",&option);
switch (option)
{
case 1: printf("enter the data\n");
scanf("%d",&item);
printf("enter the stack number\n");
scanf ("%d",&n);
push(n,item);break;
case 2: printf("enter the stack number\n");
scanf("%d",&n);
ret=pop(n);
printf("popped item is %d\n",ret);
break;
case 3:printf("enter the stack number that you want to display\n");
scanf("%d",&j);
if(top[j]==NULL)
printf("stack is empty\n");
else
{
for(temp=top[j];temp!=NULL;temp=temp->link)
printf("%d \t",temp->data);
}
break;
case 4:
exit(0);
}}}