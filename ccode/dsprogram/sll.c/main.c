#include <stdio.h>
#include <stdlib.h>
void insert();
void del();
void print();
void del_start();
void del_end();
typedef struct link
{
    int data;
    struct  link *next;

}link;
link *head=NULL;
int main()
{
    while(1){
    int a;
    printf("\n1:insert\n2:delete \n 3:print\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
            insert();
        break;
                case 2:
            del();
        case 3:
            print();
            break;
        default:
            return(0);
    }
            }
}
void insert()
{
    int ch=0;
    printf("\n1:INSERT AT AT THE START\n2:INSERT AT THE END\n");
    scanf("%d",&ch);
    if(ch==1)
    insert_at_start();
    if(ch==2)
        insert_at_end();
}
void insert_at_start()
{
    link *newnode=(link*)malloc(sizeof(link));
    printf("ENTER THE DATA\n");
    scanf("%d",&newnode->data);
   /* if(head==NULL)
    {
        newnode->next=NULL;
    }*/
   // else
        newnode->next=head;
    head=newnode;
}
void insert_at_end()
{
    link *newnode=(link*)malloc(sizeof(link));
    link *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    printf("ENTER THE DATA\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp->next=newnode;

}
void print()
{
    link *ptr=head;
    while(ptr->next!=NULL)
    {
         printf("%d\n",ptr->data);
         ptr=ptr->next;
    }


}
void del()
{
    int n=0;
    printf("\n 1:DELETE AT START \n2:DELETE AT END");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        del_start();
        break;
    case 2:
        del_end();
        break;

    }
}
void del_end()
{
    link *temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    temp->next=NULL;return;

}
void  del_start(){}
