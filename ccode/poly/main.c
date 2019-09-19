#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int co;
    int x;
    int y;
    int z;
    struct poly *next;
}poly;
poly *head1=NULL;poly *head2=NULL;poly *head3=NULL;
int main()
{
    int ch;
    poly *temp;
    printf("enter the first term\n");
    while(1)
    {
    create1();
    printf("enter 1111 to end polynomeal\n");
    scanf("%d",&ch);
    if(ch==1111)
        break;
    }
    head1=head3;
    head3=NULL;
    printf("enter the second term\n");
    while(1){
    create1();
    printf("enter 1111 to end polynomeal\n");
    scanf("%d",&ch);
    if(ch==1111)
        break;
    }
    head2=head3;
    head3=NULL;
    temp=head1;
    while(temp->next!=head1)
    {
        printf("nextterm\n");
        printf("%d*x^%d*y^%d*z^%d + ",temp->co,temp->x,temp->y,temp->z);
        temp=temp->next;
    }
    printf("%d*x^%d*y^%d*z^%d + ",temp->co,temp->x,temp->y,temp->z);
    temp=head2;
    while(temp->next!=head2)
    {
        printf("%d*x^%d*y^%d*z^%d + ",temp->co,temp->x,temp->y,temp->z);
        temp=temp->next;
    }
}

void create1()
{
    int ch;
    poly *temp=head3;
    while(temp->next!=head3&&temp!=NULL)
        temp=temp->next;
    poly *newnode=(poly*)malloc(sizeof(poly));
    printf("enter the coefficient \t");
    scanf("%d",&newnode->co);
    printf("enter the power of x \t");
    scanf("%d",&newnode->x);
    printf("enter the power of y \t");
    scanf("%d",&newnode->y);
    printf("enter the power of z \t");
    scanf("%d",&newnode->z);
   if(head3==NULL)
   {
       head3->next=newnode;
       newnode->next=head3;
       temp=newnode;

   }
   else
    {
        newnode->next=head3;
        temp->next=newnode;
        temp=newnode;

    }
}
