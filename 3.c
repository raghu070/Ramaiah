3. #include<stdio.h>
#include<string.h>
#define MAX 30
void fail(char pat[]);
int pmatch(char str[],char pat[]);
int failure[30];
int main()
{
char str[MAX],pat[MAX];
printf("enter a string & pattern\n");
scanf("%s%s",str,pat);
fail(pat);
int position= pmatch(str,pat);
if(position != -1)
printf("pat is found at %d pos",position);
else
printf("not found");
}
void fail(char *pat)
{
int i,j,n=strlen(pat);
failure[0]=-1;
for(j=1;j<n;j++)
{
i=failure[j-1];
while((pat[j]!=pat[i+1])&&(i>=0))
i=failure[i];
if(pat[j]==pat[i+1])
failure[j]=i+1;
else
failure[j]=-1;
}
for(i=0;i<n;i++)
printf("%c\t",pat[i]);
printf("\n");
for(i=0;i<n;i++)
{
printf("%d\t",failure[i]);
}
printf("\n");
}
int pmatch(char *str,char *pat)
{
int i=0,j=0;
int lenp=strlen(pat),lens=strlen(str);
while(i<lens&&j<lenp)
{
if(str[i]==pat[j])
{
i++;
j++;
}
else if(j==0)
i++;
else
j=failure[j-1]+1;
}
return ((j==lenp) ? i-lenp : -1);
}