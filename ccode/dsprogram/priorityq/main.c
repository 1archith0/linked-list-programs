#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
    int data;
    struct link *next;
}link;
link *head=NULL;
void print();
int inser();
int main()
{
   int ch=0;
   while(1){
        printf("\nenter the choice\n1:insert\n2:print\n");
        scanf("%d",&ch);
        if(ch==1)
        inser();
        else if(ch==2)
        print();
        else
        break;
   }
}
int inser()
{
        link *newnode;
        newnode=(link *)malloc(sizeof(link));
        link *temp=head;
        printf("enter the data");
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            newnode->next=NULL;
            temp=newnode;
            head=temp;
            return(0);
        }
        if(newnode->data>temp->data)
        {   newnode->next=temp;
            temp=newnode;
            head=temp;
            return(0);
        }
        while(temp->next!=NULL)
        {

            printf("\nis\t%d\ grater %d\t",newnode->data,temp->next->data);
            if(newnode->data>temp->next->data)
            {
                printf("\nYESS..%d id grater",newnode->data);
                newnode->next=temp->next;
                temp->next=newnode;return(0);

            }
            if(newnode->data==temp->data)
                return(0);
            temp=temp->next;
        }
            temp->next=newnode;
            newnode->next=NULL;
}
void print()
{
    link *temp=head;
    while(temp->next!=NULL)
    {
        printf("\t%d\t",temp->data);
        temp=temp->next;
    }
    printf("\t%d\t",temp->data);
}
