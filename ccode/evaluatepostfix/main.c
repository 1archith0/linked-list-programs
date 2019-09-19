#include <stdio.h>
#include <stdlib.h>
int stack[10],top=-1;
char exp[15];

int pop()
{
    int r=stack[top];
    top--;
    return(r);
}
void push(int i)
{
    top++;
    stack[top]=i;
}
int eva(char op,int op1,int op2)
{
    int r;
    if(op=='+')
        r=(op1+op2);
    else if(op=='-')
        r=(op1-op2);
    else if(op=='*')
        r=(op1*op2);
    else if(op=='/')
        r=(op1/op2);
    else if(op=='%')
        r=(op1%op2);
    return(r);
}

int main()
{
    printf("Enter the postfix expression\n");
    scanf("%s",exp);
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]>='0'&&exp[i]<='9')
            {push(exp[ i ]-'0');
            printf("\nprint %s\n",exp[i]);
            }
        else if(exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-'||exp[i]=='%')
        {
            int op1=pop();
            int op2=pop();
            int r=eva(exp[i],op1,op2);
            push(r);
        }
    }
    printf("\nr=%d\n",stack[top]);
}
