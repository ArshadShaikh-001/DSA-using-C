#include<stdio.h>
int main()
{
    int a[] = {4, 9, 6, 5, 0, -3, -1, -58};
    int n = sizeof(a) / sizeof(a[0]);
    int b[20];
    int i,k=0;

    //negative number
    for(i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            b[k]=a[i];
            k++;
        }
    }

    //zero number
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            b[k]=a[i];
            k++;
        }
    }

    //positive number
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            b[k]=a[i];
            k++;
        }
    }

    printf("Arranged Numbers:");
    for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}