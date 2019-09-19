
#include<stdio.h>
#include<stdlib.h>
/*implement the unbalenced bracket problem using stack which is LIFO data structure*/
int main()
{   ////////////do try to input sting less than 15 characters
    char c[15];
    int a[15];
    //c is the input string
    char stack[15];
    //to implement the usage of stack
    int i,l=0,top=-1;/*
    i :is used for the number of iteration and
    l :is used to count he total number of characters in the string
    top :keeps track of the topmost element of the stack
    */
    printf("ENTER THE STRING : ");
    scanf("%s",c);
    while(c[l]!=NULL)
        l++;
    for(i=0;i<l;i++)
    {   /*if the character in the string c is an open bracket then it is pushed into the stack*/
        if(c[i]=='('||c[i]=='{'||c[i]=='[')
            {   top++;
                a[top]=i;
                stack[top]=c[i];


            }
        /*if the character is a closing bracket then the stack[top] (opening bracket)
        is checked to the value c[i](closing bracket) */
        else if(c[i]==')'||c[i]==')'||c[i]==']')
        {
            if(c[i]=='}'&&stack[top]=='{')
                top--;

            else if(c[i]==']'&&stack[top]=='[')
                top--;

            else if(c[i]==')'&&stack[top]=='(')
                top--;
                /*if the closing is unmatched with the opening bracket then */
            else
            {

                printf("UNMATCHED BRACKET AT %d",i+1);
                return(0);
            }
        }
        else
            continue;

    }
    if(top==-1)
        printf("SUCESS");
    else
        printf("UNMATCHED BRACKET AT %d",a[top]);
    return(0);
}
