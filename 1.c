#include<stdio.h>
#define COMPARE(x,y)(((x)<(y))?-1:((x)==(y))?0:1)
#define MAX_DEGREE 100
int avail;
typedef struct
{
float coef;
int exp;
}polynomial;
polynomial terms[MAX_DEGREE];
void attach(float c,int e);
void polyadd(int sa,int fa,int sb,int fb,int *sd,int *fd);
int main()
{
int sa,fa,sb,fb,sd,fd,m,i,n;
printf("enter no.of terms in frst poly\n");
scanf("%d",&m);
printf("enter coef & exp of frst poly\n");
for(i=0;i<m;i++)
scanf("%f%d",&terms[i].coef,&terms[i].exp);
sa=0;
fa=m-1;
printf("enter no.of terms for scnd poly\n");
scanf("%d",&n);
sb=m;fb=m+n-1;
printf("enter coef & exp of scnd poly\n");
for(i=sb;i<fb;i++)
scanf("%f%d",&terms[i].coef,&terms[i].exp);
avail=m+n;
polyadd(sa,fa,sb,fb,&sd,&fd);
printf("frst poly is\n");
for(i=0;i<m;i++)
printf("%fx^%d+",terms[i].coef,terms[i].exp);
printf("scnd polynomial is\n");
for(i=sb;i<=fb;i++)
printf("%fx^%d+",terms[i].coef,terms[i].exp);
printf("resultant polynomial is \n");
for(i=sd;i<=fd;i++)
printf("%fx^%d+",terms[i].coef,terms[i].exp);
}
void polyadd(int sa,int fa,int sb,int fb,int *sd,int *fd)
{
float c;
*sd=avail;
while(sa<=fa && sb<=fb)
{
switch(COMPARE(terms[sa].exp,terms[sb].exp))
{
case -1:
attach(terms[sb].coef,terms[sb].exp);
sb++;
break;
case 0:
c=terms[sa].coef+terms[sb].coef;
if(c!=0)
attach(c,terms[sa].exp);
sa++;
sb++;
break;
case 1:
attach(terms[sa].coef,terms[sa].exp);
sa++;
}
}
for( ;sa<=fa;sa++)
attach(terms[sa].coef,terms[sa].exp);
for( ;sb<=fb;sb++)
attach(terms[sb].coef,terms[sb].exp);
*fd=avail-1;
}
void attach(float c,int e)
{
terms[avail].coef=c;
terms[avail++].exp=e;
}