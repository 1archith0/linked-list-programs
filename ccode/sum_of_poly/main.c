#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int co;
    int x,y,z;
    struct poly1 *next;
}poly;
poly *head1=NULL;
poly *head2=NULL;
poly *head3=NULL;
void input(poly*);
void print(poly*);
void add();
int main()
{
    printf("\nENTER THE FIRST POLINOMIAL\n");
    input(head1);
    printf("\nPRINTING HEAD 1\n");
    print(head1);
    printf("\nENTER THE SECOND POLINOMIAL\n");
    input(head2);
}
void input(poly *temp)
{
    int ch ;
    poly *newnode=(poly*)malloc(sizeof(poly));
    printf("ENTER 99 TO EXIT ELSE TO COTINUE\n");
    scanf("%d",&ch);
    if(ch==99)
        return;
    printf("\nENTER THE COEFECIENT\t");
    scanf("%d",&newnode->co);
    printf("\nENTER THE POWER OF X\t");
    scanf("%d",&newnode->x);
    printf("\nENTER THE POWER OF Y\t");
    scanf("%d",&newnode->y);
    printf("\nENTER THE POWER OF Z\t");
    scanf("%d",&newnode->z);
    if(temp==NULL)
    {
        printf("TEMP IS NULL");
        newnode->next=NULL;
        head=temp;
        input(head);

    }
    newnode->next=NULL;
    temp->next=newnode;
    temp=newnode;
    input(temp);

}
void print(poly *temp)
{
    while(temp->next!=NULL)
    {
        printf("%d*X^%d*Y^%d*Z^%d",temp->co,temp->x,temp->y,temp->z);
        temp=temp->next;
    }
        printf("%d*X^%d*Y^%d*Z^%d",temp->co,temp->x,temp->y,temp->z);
}
