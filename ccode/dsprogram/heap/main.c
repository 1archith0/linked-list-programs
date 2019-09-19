#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
int heap[maxsize],size=0;
void shiftup(int n);
void shiftdown(int n);
int extractmax();
int del();
int insert();
int main()
{
    int ch=0;
    while(1)
    {printf("ENTER THE CHOICE\n1:INSERT AN ELEMENT\n2:DLETE NA ELEMET\n3:EXTRACT THE MAXELEMENT\n4:print\n");
    scanf("%d",&ch);
    if(ch==2)
    {
        del();
    }
    else if(ch==1)
    {
        insert();
    }
    else if(ch==3)
    {
        extractmax();
    }
    else if(ch==4)
        print();
    else
        break;
    }
}

void shiftup(int n)
{
    printf("\nIS %d GREATER THAN %d",heap[n],heap[n/2]);
    if(heap[n]>heap[n/2])
    {   printf("\t...........YES\n");
        heap[n]=heap[n]+heap[n/2];
        heap[n/2]=heap[n]-heap[n/2];
        heap[n]=heap[n]-heap[n/2];
    }
    n=n/2;
    if(n>n/2)
    {
        shiftup(n);
    }
    else
        return;
}
void shiftdown(int n)
{
    int greater=0;
    if(heap[n]<heap[2*n])
    {
        greater= 2*n;
    }
    else if(heap[n]<heap[2*n+1])
    {
        greater =2*n+1;
    }
    else{

        return;
    }

        heap[n]=heap[n]+heap[greater];
        heap[greater]=heap[greater]-heap[n];
        heap[n]=heap[greater]-heap[n];
}
int extractmax()
{
    printf("\nTHE HIGEST VALUE IS %d",heap[0]);
    heap[0]=heap[size];
    size=size-1;
    shiftdown(0);
}
int del()
{
    int p,n=0;
    printf("\n ENTER THE VALUE TO BE DELETED :\t");
    scanf("%d",&p);
    while(n<=size)
    {
        if(heap[n]==p)
            break;
        n++;
    }
    if(n==size&&heap[n]!=p)
    {
        printf("\nELEMENT NOT FOUND");
        return ;
    }
    heap[n]=99999;
    shiftup(n);
    extractmax(n);

}

int print()
{
    int i=0;
    printf("\n");
    while(i<size)
    {
        printf("%d\t",heap[i]);
        i++;
    }
}
int insert()
{
    int p;
    printf("\nENTEF THE ELEMENT TO BE INSERTED   ");
    scanf("%d",&p);
    heap[size]=p;
    if(size>0)
    {
        if(heap[size]>heap[size/2])
        shiftup(size);
        else
        shiftdown(size);
    }
    size++;
    return;
}











