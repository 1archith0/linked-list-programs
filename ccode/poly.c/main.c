#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct poly
{
    int co;
    int x;
    int y;
    int z;
    struct poly *next;
}poly;
poly *head=NULL;
poly *head1=NULL;
poly *head2=NULL;
int add();
int eva();
int creat(poly*);
int insert(poly*);
int main()
{
    int ch;
    while(1)
    {
        printf("\nENTER YOUR CHOICE....\n1:ADD\n2:EVALUATE\nEXIT\n");
        scanf("%d",&ch);
        if(ch==1)
            add();
        if(ch==2)
            eva();
        else
            continue;
    }
}
int add()
{
    poly *temp1,*temp2;
    printf("\nVALUES OF FIRST POLYNOMEAL\n");
    creat(head1);
    head1=head;
    printf("\nVALUES OF SECOND POLYNOMEAL\n");
    creat(head2);
    head2=head;
    head=NULL;
    temp1=head1;
    temp2=head2;
    while(temp1->next!=head1)
    {
        printf("%d * x^%d * y^%d * z^%d + ",temp1->co,temp1->x,temp1->y,temp1->z);
        temp1=temp1->next;
    }
    printf("%d * x^%d * y^%d * z^%d + ",temp1->co,temp1->x,temp1->y,temp1->z);
    while(temp2->next!=head2)
    {
        printf("%d * x^%d * y^%d * z^%d + ",temp2->co,temp2->x,temp2->y,temp2->z);
        temp2=temp2->next;
    }
    printf("%d * x^%d * y^%d * z^%d = ",temp2->co,temp2->x,temp2->y,temp2->z);
    temp1=head1;
    temp2=head2;
    while(temp1->next!=head1)
    {
        while(temp2->next!=head2)
        {
            if(temp1->x==temp2->x&&temp1->y==temp2->y&&temp1->z==temp2->z)
            {
                temp1->co=temp1->co+temp2->co;
                insert(temp1);break;
            }
            temp2=temp2->next;
        }

        if(temp1->x==temp2->x&&temp1->y==temp2->y&&temp1->z==temp2->z&&temp2->next==head2)
        {
            temp1->co=temp1->co+temp2->co;
            insert(temp1);
        }
        else if((temp1->x!=temp2->x||temp1->y!=temp2->y||temp1->z!=temp2->z)&&temp2->next==head2)
            insert(temp1);
        temp1=temp1->next;
        temp2=head;
    }
    if(temp1->x==temp2->x&&temp1->y==temp2->y&&temp1->z==temp2->z&&temp1->next==head1)
        {
            temp1->co=temp1->co+temp2->co;
            insert(temp1);
        }
    else if((temp1->x!=temp2->x||temp1->y!=temp2->y||temp1->z!=temp2->z)&&temp1->next==head1)
        insert(temp1);
        temp2=head2;
        temp1=head1;
        while(temp2->next!=head2)
        {
            while(temp1->next!=head1)
            {
                if(temp1->x==temp2->x&&temp1->y==temp2->y&&temp1->z==temp2->z)
                {
                    break;
                }
                temp1=temp1->next;
            }
            if(temp1->x!=temp2->x&&temp1->y!=temp2->y&&temp1->z!=temp2->z&&temp1->next==head1)
            {
                insert(temp2);
            }
            temp1=head1;
            temp2=temp2->next;
        }
         if(temp1->x!=temp2->x&&temp1->y!=temp2->y&&temp1->z!=temp2->z&&temp2->next==head2)
            {
                insert(temp2);
            }
        printf("\b\b\b\b\b");
}
int eva()
{
    int xv,yv,zv;
    poly *temp;
    printf("ENTER VALUE OF X\n");
    scanf("%d",&xv);
    printf("ENTER VALUE OF Y\n");
    scanf("%d",&yv);
    printf("ENTER VALUE OF Z\n");
    scanf("%d",&zv);
    creat(head);
    temp=head;
    while(temp->next!=head)
    {
        insert(temp);
        temp=temp->next;
    }
    insert(temp);
    temp=head;
    int sum=0;
    while(temp->next!=head)
    {
        sum=sum+temp->co*(pow(xv,temp->x))*(pow(xv,temp->x))*(pow(xv,temp->x));
        temp=temp->next;
    }
    sum=sum+temp->co*(pow(xv,temp->x))*(pow(xv,temp->x))*(pow(xv,temp->x));
    printf("\b\b= %d",sum);

}
int creat(poly *temp)
{
    int ch;
    poly *newnode=(poly*)malloc(sizeof(poly));
    printf("\nENTER THE COEFFECIENT \n");
    scanf("%d",&newnode->co);
    printf("\nENTER THE POWER OF X\n");
    scanf("%d",&newnode->x);
    printf("\nENTER THE POWER OF Y\n");
    scanf("%d",&newnode->y);
    printf("\nENTER THE POWER OF Z\n");
    scanf("%d",&newnode->z);
    if(temp==NULL)
    {
            newnode->next=newnode;
            temp=newnode;
            head=temp;
    }
    else
    {
            newnode->next=head;
            temp->next=newnode;
            temp=newnode;

    }

    printf("\nENTER 0 TO END POLLYNOMEAL\n");
    scanf("%d",&ch);
    if(ch==0)
        return(0);
    else
        creat(temp);
}
int insert(poly *temp)
{
    printf("%d * x^%d * y^%d * z^%d + ",temp->co,temp->x,temp->y,temp->z);
}
