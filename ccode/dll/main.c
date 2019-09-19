#include <stdio.h>
#include <stdlib.h>
typedef struct employee
{
    char ssn[10];
    char name[10];
    char dep[10];
    char des[10];
    int salary;
    int phno;
    struct employee *next;
    struct employee *pre;
}emp;
void insert(int);
void delend();
void delfront();
void print(emp*);
emp *head=NULL;
int main()
{
    int ch;
     while(1)
    {
        printf("ENTER YOUR CHOICE \n");
        printf("1:Insert at end\n2:Insert at front\n3:Delete at end\n4:delete at front\n5:Display\n6:Exit\n");
        scanf("%d",&ch);
        if(ch==1)
            insert(ch);
        else if(ch==2)
            insert(ch);
        else if(ch==3)
            delfront();
        else if(ch==4)
            delend();
        else if(ch==5)
            print(head);
        else if(ch==6)
                break;
    }
}
void insert(int i)
{
    emp *newnode=(emp*)malloc(sizeof(emp));
    emp *temp=head;
    printf("enter the ssn\t");
    scanf("%s",newnode->ssn);
    printf("enter the name\t");
    scanf("%s",newnode->name);
    printf("enter the department\t");
    scanf("%s",newnode->dep);
    printf("enter the salary\t");
    scanf("%d",&newnode->salary);
    printf("enter the phno\t");
    scanf("%d",&newnode->phno);
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->pre=NULL;
        head=newnode;
    }
    else
    {
        if(i==1)
        {
            while(temp->next!=NULL)
                temp=temp->next;
            newnode->next=NULL;
            newnode->pre=temp;
            temp->next=newnode;
        }
        else if(i==2)
        {
            newnode->pre=  NULL;
            newnode->next=temp;
            temp->pre=newnode;
            temp=newnode;
            head=temp;
        }

    }
}
void delend()
{
    emp *temp=head;
    emp *prev;
    while(temp->next!=NULL)
        temp=temp->next;
    prev=temp->pre;
    prev->next=NULL;
    free(temp);
}
void delfront()
{
    emp *temp=head->next;
    emp *prev=head;
    temp->pre=NULL;
    head=temp;
    free(prev);
}
void print(emp *temp)
{
    while(temp->next!=NULL)
    {
        printf("Name\t:\t%s\tUSN\t:\t%s\tBranch\t:\t%s\tSem\t:\t%d\tPhone number\t:\t%d\n",temp->name,temp->ssn,temp->dep,temp->salary,temp->phno);
        temp=temp->next;
    }
    printf("Name\t:\t%s\tUSN\t:\t%s\tBranch\t:\t%s\tSem\t:\t%d\tPhone number\t:\t%d\n",temp->name,temp->ssn,temp->dep,temp->salary,temp->phno);
}
