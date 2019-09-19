#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,hi,j;
    int h[10]={0};
    FILE *fp;
    fp=fopen("C:\\Users\\archith vk\\Desktop\\hash.txt","r");
    for(int i=0;i<10;i++)
    {
        fscanf(fp,"%d",&n);
        hi=n%10;
        j=0;
        while(h[hi]!=0)
        {
            hi=(n+j)%10;
            j++;
        }
        h[hi]=n;
    }
    for(int i=0;i<10;i++)
        printf("\n%d\n",h[i]);
}
