#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int d;
    struct tree *l;
    struct tree *r;
}tree;
tree *head;
void insert();
void serch();
void inorder(tree*);
void postorder(tree*);
void preorder(tree*);
int main()
{
    int ch;
    while(1)
    {
        printf("\nENTER YOUR CHOICE \n");
        printf("1:Insert\n2:Search\n3:Preorder\n4:Inorder\n5:Postorder\n6:Exit\n");
        scanf("%d",&ch);
        if(ch==1)
            insert();
        else if(ch==2)
            serch();
        else if(ch==3)
            preorder(head);
        else if(ch==4)
            inorder(head);
        else if(ch==5)
            postorder(head);
        else if(ch==6)
                break;
    }
}
void insert()
{
    tree *newnode=(tree*)malloc(sizeof(tree));
    tree *temp=head;
    printf("Enter the new value\t");
    scanf("%d",&newnode->d);
    newnode->l=NULL;
    newnode->r=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(1)
        {
            if(newnode->d>temp->d)
            {
                if(temp->r==NULL)
                {
                    temp->r=newnode;break;
                }
                else
                {
                    temp=temp->r;
                }
            }
            else if(newnode->d<temp->d)
            {
                if(temp->l==NULL)
                {
                    temp->l=newnode;break;
                }
                else
                {
                    temp=temp->l;
                }
            }
        }
    }
}
void inorder(tree *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->l);
        printf("%d\t",temp->d);
        inorder(temp->r);
    }
}
void serch()
{
    tree *temp=head;
    int key;
    printf("\nEnter the key\n");
    scanf("%d",&key);
    while(1)
    {
        if(temp->d==key)
            {printf("key found..%d\n",temp->d);return;}
        else if(temp->d<key)
          if(temp->r!=NULL)
            temp=temp->r;
          else
            break;
        else if(temp->d>key)
          if(temp->l!=NULL)
            temp=temp->r;
          else
            break;
    }
    printf("key not found...\n");
}
void postorder(tree* temp)
{
    if(temp!=NULL)
    {
        inorder(temp->l);
        inorder(temp->r);
        printf("%d\t",temp->d);
    }
}
void preorder(tree* temp)
{
    if(temp!=NULL)
        {
            printf("%d\t",temp->d);
            inorder(temp->l);
            inorder(temp->r);

        }
}
