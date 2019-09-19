#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}tree;

void insert(tree *,int key);
void in(tree *);
void pre();
void post();

tree *root=NULL;
int main()
{
    int ch,d=0;
    while(1)
    {
        printf("1:INSERT\n2:INORDER\n3:POSTORDER\n4:PREEORDER");
        scanf("%d",ch);
        switch(ch)
        {
            case 1:
                printf("ENTER THE DATA TO BE INSERTED");
                scanf("%d",&d);
                insert(root,d);
            break;
            case 2:
                in(root);
            break;
            case 3:
                post();
            break;
            case 4:
                pre();
            break;
            default:
                return(0);
            break;
        }
    }
}

void insert(tree *root,int key)
{
    tree *temp=(tree *)malloc(sizeof(tree));
    temp->data=key;
    if(root==NULL)
    {
            temp->left=NULL;
            temp->right=NULL;
            root=temp;
    }
    else if(temp->data<root->data)
    {
        if(root->left!=NULL)
        {
            insert(root->left,key);
        }
        else
            root->left=temp;
    }
    else if(temp->data<root->data)
    {
        if(root->right!=NULL)
        {
            insert(root->right,key
                   );
        }
        else
        {
            root->right=temp;
        }

    }


}
void in(tree *root)
{
    in(root->left);
    printf
    ("%d",root->data);
    in(root->right);
}


void pre()
{

}
void post()
{

}






