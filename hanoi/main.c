#include <stdio.h>
#include <stdlib.h>
int n;
int main()
{
    int n;
    printf("enter the number of disks\n");
    scanf("%d",&n);
    hanoi(n,"left","right","middle");
}
void hanoi(int d,char *l,char *m,char *r)
{
    if(d>0)
    {
        hanoi(d-1,l,r,m);
        printf("move %d from %s to %s\n",d,l,r);
        hanoi(d-1,m,r,l);
    }
}
