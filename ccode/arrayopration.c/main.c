#include <stdio.h>
#include <stdlib.h>
#define size 10
int a[size];
void insert();
void del();
void print();
int n;
int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter your choice\n1:create\n2:delete\n3:insert\n4:display\n5:exit\n");
        scanf("%d",&ch);
        if(ch==2)
            del();
        else if(ch==3)
            insert();
        else if(ch==4)
            print();
        else if(ch==1)
            create();
        else if(ch==5)
            break;
    }
}
void create()
{

    printf("ENTER the number of  elements in the array\n");
    scanf("%d",&n);
    int i=0;
    while(i<n)
    {
        printf("Enter the element %d\n",i+1);
        scanf("%d",&a[i]);i++;
    }
}
void insert()
{
    int ch,e;
    printf("Enter the position at which the element is to be inserted \n");
    scanf("%d",&ch);
    ch=ch+1;
    for(int i=n;i>ch;i--)
        a[i+1]=a[i];
    printf("Enter the element to be inserted\n");
    scanf("%d",&e);
    a[ch]=e;
    n=n+1;

}
void  del()
{
    int ch;
    printf("Enter the position at which the element is to be deleted \n");
    scanf("%d",&ch);
    ch=ch+1;
    for(int i=ch;i<n;i++)
        a[i]=a[i+1];
    n=n-1;;
}
void print()
{
    int i=0;
    while(i<n)
    {
        printf("%d\t",a[i]);
        i++;
    }
}
