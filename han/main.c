#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("enter the number of disks\n");
    int d;
    scanf("%d",&d);
    hanoi(d,"left","right","middle");

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
