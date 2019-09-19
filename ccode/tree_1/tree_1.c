#include<stdio.h>
#include<stdlib.c>
void main()
{
    int n=0,i=0;
    printf("ENTER THE NUMBER OF NODES:\t");
    int *elements;
    int a[10][2];
    scanf("%d",&n);
    element=malloc(n*sizeof(int));
    printf("enter the number of elements ranging from 0-(n-1)");
    for(i=0;i<n;i++)
    {
        scanf("%d",*element);
    }
    for(i=1;i<n;i++)
    {
        for(int j=0;j<=i;j--)
            if(element[j]>element[i])
        {
            element[j]=element[i]+element[j];
            element[i]=element[j]-element[i];
            element[j]=element[j]+element[i];
        }

    }
    printf("");
}
