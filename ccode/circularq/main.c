#include <stdio.h>
#include <stdlib.h>
#define size 10
int queue[size];
int front,rear;
front=-1;
rear=-1;
void delq();
void insert();
void display();
int main()
{
    int ch;
    while(1)
    {
        printf("\n1:Insert\n2:Delete\n3:Display\n3:Exit\n");
        scanf("%d",&ch);
        if(ch==1)
            insert();
        else if(ch==2)
            delq();
        else if(ch==3)
            display();
        else if(ch==4)
            break;
    }
}
void insert()
{
    if((rear==size&&front==0)||rear==front-1)
    {
        printf("Queue is full");
        return;
    }
    else if(front==-1)
    {
        front++;rear++;
    }
    else
        rear=rear%size+1;
    printf("enter the value");
    scanf("%d",&queue[rear]);
}
void delq()
{
    if(front==-1)
    {
        printf("no item to be deleted\n");
        return;
    }
    printf("the deleted value is %d\n",queue[front]);
    if(front==rear)
    {
        front=-1;rear=-1;return;
    }
    front=front%size+1;
}
void display()
{
    if(front<rear)
    for(int i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
    if(rear<front)
    {for(int i=front;i<size;i++)
        printf("%d\t",queue[i]);
    for(int i=0;i<=rear;i++)
        printf("%d\t",queue[i]);
    }
}
