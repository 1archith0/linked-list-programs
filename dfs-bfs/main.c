#include <stdio.h>
#include <stdlib.h>
int stack[100],queue[100],top=-1,r=-1,f=0,adj[10][10],n,visit[20];
void create();
void bfs(int);
void dfs(int);
int main()
{
    int ch;
    while(1)
    {
        printf("Enter your choice\n1:create\n2:bfs\n3:dfs\n4:exit\n");
        scanf("%d",&ch);
        if(ch==1)
            create();
        else if(ch==2)
        {
            for(int i=0;i<n;i++)
                visit[i]=0;
            bfs(0);
        }
        else if(ch==3)
        {
            for(int i=0;i<n;i++)
                visit[i]=0;
            dfs(0);
            for(int i=0;i<n;i++)
            {
                if(visit[i]==1)
                    printf("\t%d",i);
                else
                    printf("\ngraph not connected");
            }
        }
    }
}
void create()
{
    printf("\ncreate\n");
    printf("enter the number of nodes\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                adj[i][j]=0;
            else
            {
                printf("\n1 connected\n0 not connected\n");
                scanf("%d",&adj[i][j]);
            }
        }
    }
}
void bfs(int v)
{
    if(visit[v]==0)
    {
        printf("\t%d\t",v);
        visit[v]=1;
    }
    for(int j=0;j<n;j++)
    {
        if((adj[v][j]==1)&&(!visit[j]))
            queue[++r]=j;
    }
    if(f<=r)
    {
        bfs(queue[f++]);
    }
}
void dfs(int v)
{
    if(visit[v]==0)
    {
       //// printf("\t%d\t",v);
        visit[v]=1;
        stack[top++]=v;
    }
        for(int i=0;i<n;i++)
    {
        if((adj[v][i]==1)&&(!visit[i]))
        {
            dfs(i);
            f=1;
        }
    }
    if(f==0&&top>-1)
    {
        dfs(stack[top--]);
    }
}
