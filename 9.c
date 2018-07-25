9. #include <stdio.h>
#include <stdlib.h>
typedef struct polynode {
int coef;
int exp;
struct polynode* link; }polynode;
struct polynode *a, *b, *c;
int compare(int a, int b)
{
if(a==b)
return 0;
if(a<b)
return -1;
if(a>b)return 1;
}
void attach(int cc,int ee, struct polynode* *ptr)
{
struct polynode* t;
t=(polynode*)malloc(sizeof(*t));
t->coef=cc;
t->exp=ee;
(*ptr)->link=t;
*ptr=t;
}
struct polynode* cpadd(struct polynode* a, struct polynode* b)
{
struct polynode *starta,*startb,*startc,*c,*rear;
rear=(polynode*)malloc(sizeof(*rear));
int sum;
starta=a;
startb=b ;
c=rear;
startc=c;
a = a->link;
b = b->link;
while(a!=starta&&b!=startb)
{
switch (compare(a->exp, b->exp))
{
case -1: attach(b->coef, b->exp, &rear);
b = b-> link;
break;
case 0:
sum = a-> coef + b-> coef;
if (sum)
attach(sum,a->exp,&rear);
a = a->link;
b = b->link;
break;
case 1: attach(a->coef,a->exp,&rear);
a = a-> link;
break;}}
for(;a!=starta;a=a->link)
attach(a->coef,a->exp,&rear);
for(;b!=startb;b=b->link)
attach(b->coef,b->exp,&rear);
rear->link=startc;
return startc;
}
void print(struct polynode* x)
{
struct polynode* sx;
sx=x;
x=x->link;
for(;x!=sx;x=x->link)
{
printf("%d x ^ %d ",x->coef,x->exp);
if(x->link!=sx)
printf("+\t");
}}
int main()
{
struct polynode *reara,*rearb,*sa,*sb,*cpol;
int n1,n2,i,c,e;
reara=(polynode*)malloc(sizeof(*reara));
rearb=(polynode*)malloc(sizeof(*rearb));
a=reara;
b=rearb;
sa=a;
sb=b;
printf("enter the number of terms in the first polynomial\n");
scanf("%d",&n1);
for(i=1;i<=n1;i++)
{
printf("enter the coef and exp\n");
scanf("%d%d",&c,&e);attach(c,e,&reara);
}
reara->link= sa;
printf("enter the number of terms in the second polynomial\n");
scanf("%d",&n2);
for(i=1;i<=n2;i++)
{
printf("enter the coef and exp\n");
scanf("%d%d",&c,&e);
attach(c,e,&rearb);
}
rearb->link= sb;
cpol=cpadd(sa,sb);
printf("\n\nthe first polynomial is\n");
print(sa);
printf("\n\nthe second polynomial is\n");
print(sb);
printf("\n\nthe sum polynomial is\n");
print(cpol);
}