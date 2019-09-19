#include <stdio.h>
#include <stdlib.h>
#define size 10
int h[size]={0};
int main()
{
    int n,hi,j=1;
    FILE *fp;
     fp = fopen("C:\\Users\\archith vk\\Desktop\\hash.txt", "r");
     for(int i=0;i<size;i++)
        printf("%d\n",h[i]);
    for(int i=0;i<size;i++)
    {
        j=1;
        fscanf(fp,"%d",&n);
        printf("%d\n",n);
        hi=n%size;
        printf("\nindex %d\n",hi);
        while(h[hi]!=0)
        {
                hi=(n+j)%size;
                j++;
        }
        h[hi]=n;
    }
    for(int i=0;i<size;i++)
    {
        printf("%d\n",h[i]);
    }
}
