5. #include<stdio.h>
typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
int isp[] = {0,19,12,12,13,13,13,0};
int icp[] = {20,19,12,12,13,13,13,0};
char expr[50];
precedence getToken(char *symbol, int *n)
{
*symbol = expr[(*n)++];
switch (*symbol)
{
case '(' : return lparen;
case ')' : return rparen;
case '+' : return plus;
case '-' : return minus;
case '/' : return divide;
case '*' : return times;
case '%' : return mod;
case '\0': return eos;
default: return operand;
} }
precedence stack[100];
int top=-1;
void printToken(precedence p)
{
if(p == rparen) printf(")");
else if (p == lparen) printf("(");
else if (p == plus) printf("+");
else if (p == minus) printf("-");else if (p == times) printf("*");
else if (p == divide) printf("/");
else if (p == mod) printf("%c",'%');
else if (p == eos) printf(" END ");
}
void push (precedence t)
{
stack[++top]=t;
}
precedence pop()
{
return stack[top--];
}
void postfix (void)
{
char symbol;
precedence token;
int n = 0;
top=0;
stack[0] = eos;
for(token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
{
if ( token == operand)
printf("%c",symbol);
else if (token == rparen) {
while (stack[top] != lparen)
printToken(pop());
pop();
}
else {
while(isp[stack[top]]>=icp[token])
printToken(pop());
push(token);
}}
while((token = pop()) != eos)
printToken(token);
printf("\n");}
int main()
{
printf("enter the infix expression");
scanf("%s",expr);
postfix();
}