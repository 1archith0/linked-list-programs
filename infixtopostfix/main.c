#include <stdio.h>
#include <stdlib.h>
char infix[20];
char stack[20];
char postfix[20];
int prority(char c);
void push(char);
char pop();
int top=-1;
int main()
{
    int j=0;
    printf("Enter the infix expression \n");
    scanf("%s",infix);
    for(int i=0;infix[i]!='\0';i++)
    {
        if(infix[i]>='a'&&infix[i]<'z')
            {
                postfix[j]=infix[i];j++;
            }
        else if(infix[i]=='(')
        {
            stack[++top]=infix[i];
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
                {postfix[j]=pop();
                j++;}
                top--;
        }
        else
        {   while(prority(stack[top])<=prority(infix[i]))
            {
                postfix[j]=pop();
                j++;
            }
            push(infix[i]);
        }
    }


    while(top!=-1)
       {
         postfix[j]=pop();
         j++;
       }

}
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    char ch=stack[top];
    top--;
    return(ch);
}
int prority(char c)
{
        if ( c == '(' )
                return ( 1 );
        else if ( c == '+' || c == '-' )
                return ( 2 );
        else if ( c == '*' || c == '/' || c == '%' )
                return ( 3 );
        else if ( c == '^' )
                return ( 4 );

}
