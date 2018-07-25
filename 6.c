6. #include<stdio.h>
#define MAX_STACK_SIZE 100 /* max stack size */
#define MAX_EXPR_SIZE 100
/* max expression size */
typedef enum {lparen, rparen, plus, minus,
times, divide, mod, eos, operand
} precedence;
int stack[MAX_STACK_SIZE]; /* global stack */
char expr[MAX_EXPR_SIZE]; /* input string */
precedence get_token(char *symbol, int *n)
{
*symbol = expr[(*n)++];
switch (*symbol)
{
case '(' : return lparen;
case ')' : return rparen;
case '+' : return plus;
case '-' : return minus;
case '*' : return times;
case '/' : return divide;
case '%' : return mod;
case '\0' : return eos;
default : return operand; /* no error checking */
}}
int push(int *top, int t){
stack[++(*top)]=t;
}
int pop( int *top )
{
return(stack[(*top)--]);
}
int eval()
{
precedence token;
char symbol;
int op1, op2;
int n = 0;
int top =-1;
token = get_token(&symbol, &n);
while (token != eos)
{
if (token == operand)
push(&top, symbol-'0');
else {
op2 = pop(&top);
op1 = pop(&top);
switch (token) {
case plus: push(&top, op1+op2); break;
case minus: push(&top, op1-op2); break;
case times: push(&top, op1*op2); break;
case divide: push(&top, op1/op2); break;
case mod: push(&top, op1%op2);break;
}}
token = get_token(&symbol, &n);
}
return pop(&top);
}
int main()
{
int result,i;
printf("ENTER THE EXPRESSION- operands and operators \n");
scanf("%s", expr);
result=eval();printf("%d",result);
}