4. #include<stdio.h>
#include<stdlib.h>
typedef struct
{
int key;
}element;
element *queue;
int front = 0,capacity = 2,rear = 0;
void addq();
element deleteq();
void queuefull();
void copy();
void display();
element a={-99};
int main()
{
queue=(element*)malloc(sizeof(element)*capacity);
element x;
int choice;
do{
printf("enter ur choice-1 addq,2 to delq,3 to display\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("enter element into queue\n");
scanf("%d",&x.key);
addq(x);
break;
case 2:
x=deleteq();
if(x.key==-99){
break;
}
printf("the element deleted is %d\n",x.key);
break;
case 3:
display();
break;
default :
printf("invalid\n");
break;
}}while(choice!=0);
}
void addq(element item)
{
rear = (rear+1)%capacity;
if(front == rear){
queuefull();
}
queue[rear]=item;
}
element deleteq()
{
element item;
if(front==rear){
printf("queue empty\n");
return a;}
front=(front+1)%capacity;
return queue[front];
}
void queuefull()
{
element *newqueue;
newqueue=(element*)malloc(sizeof(element)*capacity*2);
int start=(front+1)%capacity;
if(start<2)
copy(queue+start,queue+start+capacity-1,newqueue);
else
{
copy(queue+start,queue+capacity-1,newqueue);
copy(queue,queue+rear-1,newqueue+capacity-start);
}
front=2*capacity-1;
rear=capacity-1;
capacity*=2;
free(queue);
queue=newqueue;
}
void copy(element *start,element *end,element *newqueue)
{
int cur=0;
for(;start<end;start++)
{
newqueue[cur++].key=(*start).key;
}}
void display()
{
int cur;
if(front==rear)
{
printf("queue is empty\n");
return;
}
printf("Current circular queue is:\n");
for(cur=(front+1)%capacity; ;cur=(cur+1)%capacity)
{
printf("%d\t",queue[cur].key);
if(cur==rear){
break;
}
}}