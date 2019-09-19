#include <stdio.h>
#include <stdlib.h>
#define size 10
int v[size],adj[size][size],f=0,r=-1,top=-1,queue[50],stack[50];
void create();
void bfs(int v);
void dfs(int v);
int main()
{

}
void create()
{
    int i,j,x;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i==j)
                adj[i][j]=0;
            else
            {printf("%d %d connected 1 not connected 0",&,&);
            scanf("%d",&x);
            adj[i][j]=x;}
        }
}
void bfs(int v)
{
    int i;
    if(visit[v]==0)
    {
        printf("\n%d",v);
        visit[v]=1;
    }
    for(i=0;i<n;i++)
        if(adj[v][i]==1&&!visit[i])
        {
            queue[++r]=i;
        }
    if(f<r)
        bfs(queue[f++]);
}
void dfs(int v)
{
    if(visit[v]==0)
    {
        printf("\n%d",v);
        visit[v]=1;
        stack[++top]=v;
    }
    for(int i=0;i<n;i++)
    {
        if(ad[v][i]==1)
        {
            dfs(i);f=1
        }
    }
    if(f==0&&top>-1)
        dfs(stack[top--]);
}
