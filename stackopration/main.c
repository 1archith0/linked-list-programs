#include <stdio.h>
#include <stdlib.h>
#define size 10
void pop();
void push();
void display();
int stack[size];
int top=-1;
int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter your choice\n1:Pop\n2:Push\n3:Display\n4:Palidrome\n5:exit\n");
        scanf("%d",&ch);
        if(ch==1)
            pop();
        else if(ch==2)
            push();
        else if(ch==3)
            display();
        else if(ch==5)
            break;
        else if(ch==4)
            palidrome();
    }
}
void push()
{
    if(top==size-1)
    {
        printf("\nStack over flow\n");
        return;
    }
    top++;
    printf("\nEnter the element to be inserted\n");
    scanf("%d",&stack[top]);

}
void pop()
{
    if(top==-1)
    {
        printf("\nStack under flow\n");
        return;
    }
    --top;

}
void display()
{
    int n=0;
    while(n<top+1)
    {
        printf("%d\n",stack[n]);
        n++;
    }
}
void palidrome()
{
    int i=0,j=top;
    while(i<=j)
    {
        printf("i=%d\tj=%d\tis %d=%d\n",i,j,stack[i],stack[j]);
        if(stack[i]==stack[j])
        {
            i++;j--;
        }
        else
            {printf("it is not palidrome\n");return;}
    }
    printf("it is palidrome\n");
}
