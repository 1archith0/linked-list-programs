#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}tree;
tree *head=NULL;
void insert();
void inorder(tree *);
void preorder(tree *);
void postorder(tree*);
int main()
{
    int ch;
    while(1)
    {
        printf("\nENTER YOUR CHOICE\n1:INSERT A DIGIT\n2:PREORDER\n3:POSTORDER\n4:INORDER\n5:SERCH\nEXIT");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
            break;
            case 2:
                preorder(head);
            break;
            case 3:
                postorder(head);
            break;
            case 4:
                inorder(head);
            break;
            default:
                return;
            break;
        }


}
void creat()
{
    tree *newnode=(tree*)malloc(sizeof(tree));
    tree *temp=head;
    printf("ENTER THE DATA\n");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        newnode->left=NULL;
        newnode->right=NULL;
        head=newnode;
    }
    else
    {
        while(1)
        {
            if(temp->data>newnode->data)
            {
                if(temp->left==NULL)
                {
                    newnode->left=NULL;
                    newnode->right=NULL;
                    temp->left=newnode;
                    break;
                }
                else
                {
                    temp=temp->left;
                    continue;
                }
            }
            if(temp->data<newnode->data)
            {
                if(temp->right==NULL)
                {
                    newnode->left=NULL;
                    newnode->right=NULL;
                    temp->right=newnode;
                    break;
                }
                else
                {
                    temp=temp->right;
                    continue;
                }
            }

        }
    }

}
void inorder(tree *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}
void postorder(tree *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        inorder(temp->right);
        printf("%d\t",temp->data);
    }
}
void preorder(tree *temp)
{
    if(temp!=NULL)
    { printf("%d\t",temp->data);
        inorder(temp->left);
        inorder(temp->right);
    }
    return;

}


