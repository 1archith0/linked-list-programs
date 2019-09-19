#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    char usn[11];
    char name[15];
    char branch[5];
    int sem;
    int phno;
    struct student *next;
}s;
s *head;
void insert(int);
void delfront();
void delend();
void print(s*);
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
    s *newnode=(s*)malloc(sizeof(s));
    s *temp=head;
    printf("enter the usn\t");
    scanf("%s",newnode->usn);
    printf("enter the name\t");
    scanf("%s",newnode->name);
    printf("enter the branch\t");
    scanf("%s",newnode->branch);
    printf("enter the sem\t");
    scanf("%d",&newnode->sem);
    printf("enter the phno\t");
    scanf("%d",&newnode->phno);
    if(head==NULL)
    {
        newnode->next= NULL;
        head=newnode;
    }
    else
    {
        if(i==1)
        {
          while(temp->next!=NULL)
                temp=temp->next;
          newnode->next=NULL;
          temp->next=newnode;
        }
        else if(i==2)
        {
            newnode->next=temp;
            temp=newnode;
            head=temp;
        }

    }
}
void delfront()
{
    s *temp=head;
    head=head->next;
    free(temp);
}
void delend()
{
    s *temp=head,*n;
    while(temp->next->next!=NULL)
        temp=temp->next;
    n=temp->next;
    temp->next=NULL;
    free(n);
}

void print(s *temp)
{
    while(temp->next!=NULL)
    {
        printf("Name\t:\t%s\tUSN\t:\t%s\tBranch\t:\t%s\tSem\t:\t%d\tPhone number\t:\t%d\n",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
        temp=temp->next;
    }
    printf("Name\t:\t%s\tUSN\t:\t%s\tBranch\t:\t%s\tSem\t:\t%d\tPhone number\t:\t%d\n",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
}
