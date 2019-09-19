#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
    int data ;
    struct link *pre;
    struct link *next;
}link;
link *head=NULL;
void del();
void ins();
void print();
int main()
{
    int ch=0;
    while(1)
    {
    printf("1:INSERT\n2:DELETE\n3:PRINT");
    scanf("%d",&ch);
    while(1)
    switch(ch)
    {
        case 1:
            ins();
        break;
        case 2:
            del();
        break;
        case 3:print();
        break;
        default:
        return(0);
    }
    }
}

void ins()
{
    int ch=0;int d=0;
    link *newnode=(link *)malloc(sizeof(link));
    printf("\n1:INSERT AT THE BEGINNING \n2:INSERT AT THE END\n3:INSERT IN THE MIDDLE");
    scanf("%d",&ch);
    printf("ENTER THE DATA\t");
    scanf("%d",&newnode->data);
    if(ch==1)
    {
        if(head==NULL)
        {
            newnode->pre=NULL;
            newnode->next=NULL;
            head=newnode;
        }

        newnode->pre=NULL;
        newnode->next =head;
        head->pre=newnode;
        head=newnode;
    }
    else if(ch==2)
    {
        if(head==NULL)
        {
            newnode->pre=NULL;
            newnode->next=NULL;
            head=newnode;
        }
        while(head->next!=NULL)
            head=head->next;

        newnode->pre=head;
        newnode->next =NULL;
        head->next=newnode;
        while(head->pre!=NULL)
            head=head->pre;

    }
    else if(ch==3)
    {

        link *temp=head;
        printf("\nENTER THE DATA TO BE SERCHED\n");
        scanf("%d",&d);
        if(head==NULL)
        {
            newnode->pre=NULL;
            newnode->next=NULL;
            head=newnode;
        }
        while(temp->data!=d)
        {
            temp=temp->next;
        }
        printf("ENTER THE DATA TO BE INSERTED");

        newnode->pre=temp->pre;
        newnode->next=temp->next;
        temp->pre->next=newnode;
        temp->pre->next=newnode;
        while(temp->pre!=NULL)
            temp=temp->pre;
        head=temp;
    }
}
void del()
{
    link *temp=head->next;
    temp->pre=NULL;
    int ch=0;
    printf("\n1:DELETE AT THE BEGINNING \n2:DELETE AT THE END\n3:DELETE IN THE MIDDLE");
    scanf("%d",&ch);
    if(ch==1)
    {
        head->next=NULL;
        free(head);
        head=temp;
    }
    else if(ch==2)
    {
        while(head->next->next!=NULL)
        {
            head=head->next;
        }
        temp=head;
        free(temp);
        while(temp->pre!=NULL)
            temp=temp->pre;

    }
    else if(ch==3)
    {
        printf("ENTER THE DATA TO DELETED");
        scanf("%d",&ch);
        while(head->next!=ch)
            head=head->next;
        head->pre->next=head->pre;
        head->next->pre=head->next;
    }


}

void print()
{
    int ch=0;
    printf("\n1:PRINT FROM FIRST TO LAST\n2:PRINT FROM LAST TO FIRST\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        while(head->next!=NULL)
            {
                printf("\t%d\t",head->data);
                head=head->next;
            }
            while(head->pre!=NULL)
                head=head->pre;
    }
    else if(ch==2)
    {
        while(head->next!=NULL)
            {
                head=head->next;
            }
        while(head->pre!=NULL)
        {
            printf("\t%d\t",head->data);
            head=head->pre;
        }

    }
}
