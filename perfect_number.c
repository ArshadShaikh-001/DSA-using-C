#include<stdio.h>
int main()
{
    int num,sum=0;
    printf("Enter a number to check whether it is perfect number or not:");
    scanf("%d",&num);

    for(int i=1;i<=num/2;i++)
    {
        if(num%i==0)
        {
            sum+=i;
        }
    }

    if(sum==num && num!=0)
    {
        printf("it is the perfect number");
    }
    else
    {
        printf("it is not perfect number");
    }
    return 0;
}
