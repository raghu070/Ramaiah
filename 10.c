10. #include <stdio.h>
#include<stdlib.h>
typedef struct node
{
struct node* llink;
int data;
struct node* rlink;
}node;
struct node* head;
void insert(int item)
{
struct node *temp;
temp=(node*)malloc(sizeof(*temp));
temp->data=item;
if(head->rlink==head)
{
head->rlink=temp;
head->llink=temp;
temp->rlink=temp->llink=head;
}
else
{
temp->rlink=head->rlink;
head->rlink->llink=temp;
temp->llink=head;
head->rlink=temp;
}
}
int del(int item)
{
struct node *temp,*trail;
temp=(node*)malloc(sizeof(*temp));
temp=head;
temp=temp->rlink;
while(temp!=head)
{
if(item==temp->data)
{
trail=temp->llink;
trail->rlink=temp->rlink;
temp->rlink->llink=trail;
free(temp);
}
temp=temp->rlink;
}
}
void printfwd()
{
struct node *temp;
temp=(node*)malloc(sizeof(*temp));
printf("list in forward direction is \n");
for(temp=head->rlink;temp!=head;temp=temp->rlink)
printf("%d\t",temp->data);
printf("\n");
}
void printrev()
{
struct node *temp;
temp=(node*)malloc(sizeof(*temp));
printf("list in reverse direction is \n");
for(temp=head->llink;temp!=head;temp=temp->llink)
printf("%d\t",temp->data);
printf("\n");
}
int main()
{
head=(node*)malloc(sizeof(*head));
head->rlink=head;
head->llink=head;
int op,key;
while(1)
{
printf("1.insert\n2.delete a node\n3.display in forward direction\n4.display in reverse direction\n5.exit\n");
scanf("%d",&op);
switch(op)
{
case 1: printf("enter the data\n");
scanf("%d",&key);
insert(key);
break;
case 2: printf("enter the data of the node to be deleted\n");
scanf("%d",&key);
del(key);
break;
case 3:printfwd();
break;
case 4: printrev();
break;
case 5: exit(0);
break;
}
}
}