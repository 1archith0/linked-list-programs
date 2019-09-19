#include <stdio.h>
#include <stdlib.h>
/*Design, Develop and Implement a menu driven Program in C for the following operations on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo
a.	Creating a SLL of N Students Data by using front insertion
b.	Display the status of SLL and count the number of nodes in it
c.	Perform Insertion / Deletion at End of SLL
d.	Perform Insertion / Deletion at Front of SLL (Demonstration of stack)
e.	Exit
*/
typedef struct student_t_distribution
{
    char usn[10];
    char name[10];
    char b[10];
    int sem;
    int phno;
    struct student *next;
}s;
void insert(int);
void delfront();
void delend();
void des();
s *head=NULL;
int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter your choice\n1:insert at front\n2:delete at front\n3:insert at end\n4:delete at end\n5:display\n6:exit\n");
        scanf("%d",&ch);
        if(ch==1||ch==3)
            insert(ch);
        else if(ch==2)
            delfront();
        else if(ch==4)
            delend();
        else if(ch==5)
            des();
        else if(ch==6)
            return(0);
    }

}
void insert(int ch)
{
    printf("enter insert\n");
    s *newnode=(s*)malloc(sizeof(s));
    s *temp;
    printf("Enter the usn\n");
    scanf("%s",newnode->usn);
    printf("Enter the name\n");
    scanf("%s",newnode->name);
    printf("Enter the branch\n");
    scanf("%s",newnode->b);
    printf("Enter the sem\n");
    scanf("%d",&newnode->sem);
    printf("Enter the phone number\n");
    scanf("%d",&newnode->phno);
    if(head==NULL)
    {
        newnode->next=NULL;
        temp=newnode;
        head=temp;
        return;
    }
    if(ch==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else if(ch==2)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->next=NULL;
        temp->next=newnode;
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
    s *temp=head;
    s *pre;
    while(temp->next!=NULL)
    {
        pre=temp;
        temp=temp->next;
    }
    free(temp);
    pre->next=NULL;


}
void des()
{
    s *temp=head;
    while(temp!=NULL)
    {
        printf("usn\t:%s\tname\t:%s\tbranch\t:%s\tsem\t:%d\tphno\t:\t%d\n",temp->usn,temp->name,temp->b,temp->sem,temp->phno);
        temp=temp->next;
    }

}
