2. #include<stdio.h>
#define MAX 20
#define MAX_SIZE 50
typedef struct
{
int row,col,val;
}terms;
void sparsematrix(int mat[][MAX], int row, int col,terms* a)
{
int i,j,val=0,cur=1;
a[0].row=row;
a[0].col=col;
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
if(mat[i][j]!=0)
{
a[cur].row=i;
a[cur].col=j;
a[cur++].val=mat[i][j];
++val;
}
}
}
a[0].val=val;
}
void fasttranspose(terms *a,terms *b)
{
int i,j,rowterms[MAX]={0},startingpos[MAX]={0};
b[0].col=a[0].row;
b[0].row=a[0].col;
b[0].val=a[0].val;
for(i=1;i<=a[0].val;i++)
rowterms[a[i].col]++;
startingpos[0]=1;
for(i=1;i<a[0].col;i++)
startingpos[i]=rowterms[i-1]+startingpos[i-1];
printf("rowterms:");
for(i=0;i<a[0].col;i++)
{
printf("%d\t",rowterms[i]);
}
printf("/n");
printf("strgpostn:");
for(i=0;i<a[0].col;i++)
printf("%d\t",startingpos[i]);
printf("\n");
for(i=1;i<=a[0].val;i++)
{
j=startingpos[a[i].col]++;
b[j].col=a[i].row;
b[j].row=a[i].col;
b[j].val=a[i].val;
}
}
int main()
{
terms a[MAX_SIZE];
int i,j,row,col,mat[MAX][MAX];
terms b[MAX_SIZE];
printf("enter no.of rows & cols\n");
scanf("%d%d",&row,&col);
printf("enter elements\n");
for(i=0;i<row;i++)
for(j=0;j<col;j++)
scanf("%d",&mat[i][j]);
sparsematrix(mat,row,col,a);
printf("sparse matrix is: \n");
printf("row\tcol\tval\n");
for(i=0;i<=a[0].val;i++)
printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
printf("\n");
fasttranspose(a,b);
printf("transpose of matrix is:\n");
for(i=0;i<=b[0].val;i++)
{
printf("%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);
}
printf("\n");
return 0;
}