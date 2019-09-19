#include <stdio.h>
#include <stdlib.h>
void insert();
void del();
void des();
#define size 10
int queue[size];
int front=-1,rear=-1;
int main()
{
   int ch;
   while(1)
   {
       printf("\nEnter your choice\n1:Insert\n2:Delete\n3:Display\n4:Exit\n");
       scanf("%d",&ch);
        if(ch==1)
            insert();
        else if (ch==2)
            del();
        else if(ch==3)
            des();
        else if(ch==4)
            return(0);
   }
}
void insert()
{
    if((front==size-1&&rear==0)||(rear==front-1))
    {
        printf("queue is full");
        return;
    }
    printf("\nEnter the new number\n");
    if(rear==-1)
        front=0;
    rear=(rear+1)%10;
    scanf("%d",&queue[rear]);
}
void del()
{
    if(rear=-1&&front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    if(rear==front)
    {
        rear=-1;front=-1;
    }
    else
    front++;
}
void des()
{
    int a;
    for(a=0;a<=rear;a++)
        printf("%d\t",queue[a]);
}
