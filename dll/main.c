#include <stdio.h>
#include <stdlib.h>
typedef struct employee
{
    char usn[10];
    char name[10];
    char b[10];
    int sem;
    int phno;
    struct student *next;
    struct student *next;
}emp;

void insert(int);
void delfront();
void delend();
void des();
emp *head=NULL;
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


}
