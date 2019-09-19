#include <stdio.h>
#include <stdlib.h>
char pop();
void push(char n);
#define size 10
int top=-1;
char stack[size];
int priority(char ch);
void main()
{
    int l=0;
    char infix[15],postfix[15];
    printf("ENTER THE IFIX EXPRESSION");
    scanf("%s",infix);
    while(infix[l]!='\0')
        l++;
    int j=0;
    for(int i=0;i<l;i++)
    {
        if(infix[i]>='a'||infix[i]<='z')
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
                    postfix[j++]=pop();
            top--;
        }
        else if(infix[i]=='(')
                push(infix[i]);
        else
        {
            while(priority(stack[top])>=priority(infix[i]))
            {
                postfix[j++]==pop();
            }push(infix[i]);
        }
    }
    while(top>-1)
    {
        postfix[j++]=pop();
    }
    printf("\n\n\n\n\n\n%s",postfix);
}
void push(char n)
{
    if(top==size)
        return;
    top++;
    stack[top]=n;
}
char pop()
{
    if(top==-1)
        return;
    top--;
    return(stack[top+1]);
}
int priority(char ch)
{
    if(ch=='(')
        return(1);
    else if(ch=='+'||ch=='-')
        return(2);
    else if(ch=='/'||ch=='*'||ch=='%')
        return(3);
    else if(ch=='^')
        return(4);
}
